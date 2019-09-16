#! /usr/bin/python
import time
import os.path
import tornado.httpserver
import tornado.websocket
import tornado.ioloop
import tornado.web
import RPi.GPIO as GPIO

#Initialize Raspberry PI GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(16, GPIO.OUT) #led
GPIO.setup(18, GPIO.OUT) #led
##2 wheels for demo
GPIO.setup(29, GPIO.OUT) #left
GPIO.setup(31, GPIO.OUT)

GPIO.setup(33, GPIO.OUT) #right
GPIO.setup(35, GPIO.OUT)

#Tornado Folder Paths
settings = dict(
	template_path = os.path.join(os.path.dirname(__file__), "templates"),
	static_path = os.path.join(os.path.dirname(__file__), "static")
	)

#Tonado server port
PORT = 80


class MainHandler(tornado.web.RequestHandler):
  def get(self):
     print "[HTTP](MainHandler) User Connected."
     self.render("index.html")

	
class WSHandler(tornado.websocket.WebSocketHandler):
  def open(self):
    print '[WS] Connection was opened.'
 
  def on_message(self, message):
    print '[WS] Incoming message:', message
    if message == "on_g":
      GPIO.output(16, True)
    if message == "off_g":
      GPIO.output(16, False)
    if message == "on_r":
      GPIO.output(18, True)
    if message == "off_r":
      GPIO.output(18, False)

    ##----LEFT----##
    if message == "LEFT_1":
      GPIO.output(33, True)
      GPIO.output(29, False)
    if message == "LEFT_0":
      GPIO.output(33, False)

    ##----RIGHT----##
    if message == "RIGHT_1":
      GPIO.output(29, True)
      GPIO.output(33, False)
    if message == "RIGHT_0":
      GPIO.output(29, False)

    ##----FORWARD----##
    if message == "FORWARD_1":
      GPIO.output(29, True)
      GPIO.output(33, True)
    if message == "FORWARD_0":
      GPIO.output(29, False)
      GPIO.output(33, False)

    ##----BACKWARD----##
    if message == "BACKWARD_1":
      GPIO.output(31, True)
      GPIO.output(35, True)
    if message == "BACKWARD_0":
      GPIO.output(31, False)
      GPIO.output(35, False)

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
        main_loop.start()

    except:
        print "Exception triggered - Tornado Server stopped."
        GPIO.cleanup()

#End of Program
