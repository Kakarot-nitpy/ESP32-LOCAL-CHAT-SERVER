#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

const char* ssid = "ESP32 CHAT SERVER BY HEC";
const char* password = "123HEC456";

WebServer server(80);
WebSocketsServer webSocket(81);

// Temporary webpage
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>MY WORLD</title>
</head>
<body>

<h2>Chat Server</h2>

<input id="msg" type="text" placeholder="Enter message">
<button onclick="sendMsg()">Send</button>

<div id="chat"></div>

<script>

var gateway = "ws://" + window.location.hostname + ":81/";
var websocket;

window.onload = function(){
    websocket = new WebSocket(gateway);

    websocket.onmessage = function(event){
        document.getElementById("chat").innerHTML +=
        "<p>" + event.data + "</p>";
    };
}

function sendMsg(){

    var text = document.getElementById("msg").value;

    websocket.send(text);

    document.getElementById("msg").value="";
}

</script>

</body>
</html>
)rawliteral";

void webSocketEvent(uint8_t num,
                    WStype_t type,
                    uint8_t * payload,
                    size_t length)
{

    switch(type)
    {

        case WStype_CONNECTED:
        {
            Serial.printf("Client %u Connected\n", num);
            break;
        }

        case WStype_DISCONNECTED:
        {
            Serial.printf("Client %u Disconnected\n", num);
            break;
        }

        case WStype_TEXT:
        {
            String msg = String((char*)payload);

            Serial.println(msg);

            // Broadcast message to everyone
            webSocket.broadcastTXT(msg);

            break;
        }

        default:
        break;
    }
}

void setup()
{

    Serial.begin(115200);

    WiFi.softAP(ssid, password);

    Serial.println();
    Serial.println("WiFi Started");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());

    server.on("/", []()
    {
        server.send(200, "text/html", webpage);
    });

    server.begin();

    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    Serial.println("Server Started");
}

void loop()
{
    server.handleClient();
    webSocket.loop();
}