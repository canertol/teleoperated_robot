var ws; //global variable

$(document).ready(function(){

        var WEBSOCKET_ROUTE = "/ws";

        if(window.location.protocol == "http:"){
            //localhost
            ws = new WebSocket("ws://" + window.location.host + WEBSOCKET_ROUTE);
            }
        else if(window.location.protocol == "https:"){
            //Dataplicity
            ws = new WebSocket("wss://" + window.location.host + WEBSOCKET_ROUTE);
            }

        ws.onopen = function(evt) {
            $("#ws-status").html("Connected");
            };

        ws.onmessage = function(evt) {
            };

        ws.onclose = function(evt) {
            $("#ws-status").html("Disconnected");
            };

        $("#green_on").click(function(){
            ws.send("on_g");
            });

        $("#green_off").click(function(){
            ws.send("off_g");
            });

        $("#red_on").click(function(){
            ws.send("on_r");
            });

        $("#red_off").click(function(){
            ws.send("off_r");
            });
        
        ws.onkeydown = function (event) {

            var keyCode = event.keyCode;
            if(keyCode == 37) {
            ws.send("LEFT_1");
            }
            else if(keyCode == 39) {
                ws.send("RIGHT_1");
            }
            else if(keyCode == 38) {
                ws.send("FORWARD_1");
            }
            else if(keyCode == 40) {
                ws.send("BACKWARD_1");
            }
            else if(keyCode == 32) {
                ws.send("KICK_1");
            }
        };

        ws.onkeyup = function (e) {

            var keyCode = e.keyCode;
            if(keyCode == 37) {
            ws.send("LEFT_0");
            }
            else if(keyCode == 39) {
                ws.send("RIGHT_0");
            }
            else if(keyCode == 38) {
                ws.send("FORWARD_0");
            }
            else if(keyCode == 40) {
                ws.send("BACKWARD_0");
            }
            else if(keyCode == 32) {
                ws.send("KICK_0");
            }
        };
        
        

      });
