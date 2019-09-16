#! /usr/bin/python
import time
import os.path
import tornado.httpserver
import tornado.websocket
import tornado.ioloop
import tornado.web
import json
import serial
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
  def open(self):
    print '[WS] Connection was opened.'
 
  def on_message(self, message):

    if type(message) is []:
      print '[WS] Incoming message:', message
      #message = message.encode()
#      if message == '1':
#       ser.write(b'1')
    else:
#      if isinstance(message, str):
	print message
	ser.write(message.encode())	
      #print message
      #message = message.encode()
      #if message == 'data0':
       #ser.write(b'0')
      #if message == 'data1':
      # ser.write(b'1')
      #if message == 'data2':
      # ser.write(b'2')
      #if message == 'data3':
      # ser.write(b'3')
      #if message == 'data4':
      # ser.write(b'4')
      #if message == 'data5':
      # ser.write(b'5')
      #if message == 'data6':
      # ser.write(b'6')
      #if message == 'data7':
      # ser.write(b'7')
      #if message == 'data8':
      # ser.write(b'8')
      #if message == 'data9':
      # ser.write(b'9')

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
