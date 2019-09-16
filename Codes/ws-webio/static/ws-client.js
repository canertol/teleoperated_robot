var ws; //global variable
var logContainer;

//Joystick
var previousX0 = 0;
var previousY0 = 0;
var previousX1 = 0;
var previousY1 = 0;

var posOffset = 5; 

// Buttons
var activeButtons = {};

//var gamepad = navigator.getGamepads()[0];
$(document).ready(function () {

  logContainer = $('.js-log');

  var WEBSOCKET_ROUTE = "/ws";

  if (window.location.protocol == "http:") {
    //localhost
    ws = new WebSocket("ws://" + window.location.host + WEBSOCKET_ROUTE);
  }
  else if (window.location.protocol == "https:") {
    //Dataplicity
    ws = new WebSocket("wss://" + window.location.host + WEBSOCKET_ROUTE);
  }

  ws.onopen = function (evt) {
    $("#ws-status").html("Connected");
  };

  
  ws.onmessage = function (evt) {
      var li = document.createElement('li');
      li.innerText = evt.data;
      logContainer.prepend(li);    
  };

  ws.onclose = function (evt) {
    $("#ws-status").html("Disconnected");
  };

  $('html').keydown(function (event) {

  });

  $('html').keyup(function (e) {


  });
});


var haveEvents = 'ongamepadconnected' in window;
var controllers = {};

var lastPress;


var A_BUTTON = 0;
var B_BUTTON = 1;
var X_BUTTON = 2;
//var Y_BUTTON = 3;
var L_BUTTON = 4; //find the correct button index
var R_BUTTON = 5; //find the correct button index

function createButtonMessage(button, active) {
  var message = {
    'type' : 'button', 'button' : {
      'index' : button, 'active' : active 
    }
  };

  return JSON.stringify(message);
}

function onButtonPress(button) {

  activeButtons[button] = true;
  ws.send(createButtonMessage(button, true));
  return true;


  if (button === X_BUTTON) {
    ws.send(createButtonMessage(X_BUTTON));
//    console.log("X Button");
  }

  if (button === A_BUTTON) {
    ws.send(createButtonMessage(A_BUTTON));
    //ws.send("DRIBBLE ON");
    //console.log("A Button");
  }

  if (button === B_BUTTON) {
    ws.send(createButtonMessage(B_BUTTON));
    //console.log("B Button");
  }

  if (button === L_BUTTON) {
    ws.send(createButtonMessage(L_BUTTON));
    //console.log("L Button");
  }

  if (button === R_BUTTON) {
    ws.send(createButtonMessage(R_BUTTON));
    //console.log("R Button");
  }

}

function onButtonRelease(button) {
  activeButtons[button] = false;
  ws.send(createButtonMessage(button, false));
}


function connecthandler(e) {
  addgamepad(e.gamepad);
}

function addgamepad(gamepad) {
  controllers[gamepad.index] = gamepad;
  requestAnimationFrame(updateStatus);
  console.log("gamepad eklendi")
}

function disconnecthandler(e) {
  removegamepad(e.gamepad);
}

function removegamepad(gamepad) {
  delete controllers[gamepad.index];
}

function updateStatus() {
  if (!haveEvents) {
    scangamepads();
  }

  var i = 0;
  var j;

  for (j in controllers) {
    var controller = controllers[j];
    for (i = 0; i < controller.buttons.length; i++) {
      var button = controller.buttons[i];

      if(button.pressed && !activeButtons[i]) {
        onButtonPress(i);
      }

      if(!button.pressed && activeButtons[i]) {
        onButtonRelease(i);
      }
    }
}



//  console.log({ index: 0, axes: controller.axes[0] } );
//  console.log({ index: 1, axes: controller.axes[1] } );



  var x0 = Math.round(100*controller.axes[0]);
  var y0 = -1*Math.round(100*controller.axes[1]);
  var x1 = Math.round(100*controller.axes[2]);
  var y1 = -1*Math.round(100*controller.axes[5]);

  if (Math.abs(x0 - previousX0) > posOffset || Math.abs(y0 - previousY0) > posOffset) {

    var message = {
      'type': 'stick',
      'value': {
        'index': 0,
        'x': x0,
        'y': y0,
      }
    };

    previousX0 = x0;
    previousY0 = y0;
    console.log(message);
    ws.send(JSON.stringify(message));
  }
  
  if (Math.abs(x1 - previousX1) > posOffset || Math.abs(y1 - previousY1) > posOffset) {

    var message = {
      'type': 'stick',
      'value': {
        'index': 1,
        'x': x1,
        'y': y1,
      }
    };

    previousX1 = x1;
    previousY1 = y1;
    console.log(message);
    ws.send(JSON.stringify(message));
  }

  
  //console.log(Math.sqrt(Math.pow(controller.axes[0],2) + Math.pow(controller.axes[1],2)));
  requestAnimationFrame(updateStatus);

}

//var axes = d.getElementsByClassName("axis");
//for (i = 0; i < controller.axes.length; i++) {
//  var a = axes[i];
//  a.innerHTML = i + ": " + controller.axes[i].toFixed(4);
//  a.setAttribute("value", controller.axes[i] + 1);
//}

function scangamepads() {
  var gamepads = navigator.getGamepads ? navigator.getGamepads() : (navigator.webkitGetGamepads ? navigator.webkitGetGamepads() : []);
  for (var i = 0; i < gamepads.length; i++) {
    if (gamepads[i]) {
      if (gamepads[i].index in controllers) {
        controllers[gamepads[i].index] = gamepads[i];
      } else {
        addgamepad(gamepads[i]);
      }
    }
  }
}


window.addEventListener("gamepadconnected", connecthandler);
window.addEventListener("gamepaddisconnected", disconnecthandler);

if (!haveEvents) {
  setInterval(scangamepads, 500);
}
