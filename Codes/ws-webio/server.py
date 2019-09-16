#! /usr/bin/python
import time
import os.path
import tornado.httpserver
import tornado.websocket
import tornado.ioloop
import tornado.web
import json
import serial
import numpy as np
import math
import sys
#import RPi.GPIO as GPIO
from subprocess import call
#Initialize Raspberry PI GPIO
#GPIO.setmode(GPIO.BOARD)
#GPIO.setup(16, GPIO.OUT) #led
#GPIO.setup(18, GPIO.OUT) #led
##2 wheels for demo
#GPIO.setup(29, GPIO.OUT) #left
#GPIO.setup(31, GPIO.OUT)

#GPIO.setup(33, GPIO.OUT) #right
#GPIO.setup(35, GPIO.OUT)

#Tornado Folder Paths
settings = dict(
	template_path = os.path.join(os.path.dirname(__file__), "templates"),
	static_path = os.path.join(os.path.dirname(__file__), "static")
	)

#Tonado server port
PORT = 80
ser = serial.Serial('/dev/ttyUSB0',9600)


class MainHandler(tornado.web.RequestHandler):
  def get(self):
     print "[HTTP](MainHandler) User Connected."
     self.render("index.html")

	
class WSHandler(tornado.websocket.WebSocketHandler):

  BUTTON_DRIBBLE = 6
  BUTTON_KICK = 7
  #L_BUTTON_TURN_LEFT = 4
  #R_BUTTON_TURN_RIGHT = 5
	

  def open(self):
    print '[WS] Connection was opened.'

    
 
  def on_message(self, message):
    print message
#    distance1 = ord(ser.read())
 #   distance2 = ord(ser.read())
  #  distance3 = ord(ser.read())
   # distance4 = ord(ser.read())
   # print distance1, distance2, distance3, distance4
   # print message
    obj  = json.loads(message)
    if obj["type"] == "stick":
      pos = obj["value"]
      ind = chr(pos["index"])
      print "X: {} : Y: {}".format(pos["x"], pos["y"])
      x = float( pos["x"])
      y = float( pos["y"])
      if x == 0:
        if y>0: # x=0 y>0
          theta = 90
        elif y==0: # x=y=0
          theta = 0
        else: #x = 0 y<0
          theta = 270
      elif x > 0:
        if y > 0: # x>0 y>0
          theta = np.arctan(y/x)
          theta = (theta*360)/(2*math.pi)
        else: #x>0 y<=0
          theta = np.arctan(y/x)
          theta = 360 + (theta*360)/(2*math.pi)
      else: # x<0
        theta = np.arctan(y/x)
        theta = 180 + (theta*360)/(2*math.pi)

      theta = chr(int(theta*127/360))
      mag = chr(int(int(math.sqrt(x**2+y**2)*127.0/140.0))) #maximum magnitude is assumed 140
#      print theta,mag
      print ord(theta), ord(mag)
      #	data_enc = data.encode()   #encoded string
      #	data.append(int(theta))
      #	data.append(int(mag))
      #	print data, type(data[0])	 
      #	time.sleep(1)

    else:
      ind = chr(2)
      button = obj["button"]
      index = chr(button["index"])
      value = chr(int(button["active"]))

    if ind == chr(2):
      data = ind+index+value
      print "button",ord(ind), ord(index), ord(value)
    else:
      data = ind+theta+mag
     #   print sys.getsizeof(data), type(data)
      print ord(ind), ord(theta), ord(mag)
    ser.write(data)     #to ardiuno   
    

    self.write_message("Server response")


  def on_close(self):
    print '[WS] Connection was closed.'


application = tornado.web.Application([
  (r'/', MainHandler),
  (r'/ws', WSHandler),
  ], **settings)


if __name__ == "__main__":
    try:
        http_server = tornado.httpserver.HTTPServer(application)
        http_server.listen(PORT)
        main_loop = tornado.ioloop.IOLoop.instance()

        print "Tornado Server started"
#        call(
#       	[ "mjpg_streamer",
#      	" -i",
#      	"input_uvc.so -r 200x200-d /dev/video0 -f 8 -q 1",
#   		 " -o",
#   	 "output_http.so -p 5901 -w /usr/local/share/mjpg-streamer/www",
#  	"&"
# 	]
#	)
	main_loop.start()

    except:
        print "Exception triggered - Tornado Server stopped."
        #GPIO.cleanup()

#End of Program
