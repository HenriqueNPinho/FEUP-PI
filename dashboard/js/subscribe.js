mqtt_server = "localhost";
mqtt_port = 9001;
mqtt_destname = "feup/dei/secretaria";
const clientID = "web" + new Date().getTime();

window.onload = sub_mqtt_msg;

function send_mqtt_msg(table) {
  var element = document.getElementById("color" + table);
    console.log(element.className);
    var mqtt_msg = "";
    if (element.className == "estado_green") {
      mqtt_msg = `{ "desk": "${table}", "sensor": "Unavailable" }`;
      renderLeic(mqtt_msg);
    }

    if (element.className == "estado_red") {
      mqtt_msg = `{ "desk": "${table}", "sensor": "Away" }`;
      renderLeic(mqtt_msg);
    }

    if (element.className == "estado_yellow") {
      mqtt_msg = `{ "desk": "${table}", "sensor": "Free" }`;
      renderLeic(mqtt_msg);
    }
    console.log(mqtt_msg);

    message = new Paho.MQTT.Message(mqtt_msg);
    message.destinationName = mqtt_destname;
    client.send(message);
}

function sub_mqtt_msg() {
  client = new Paho.MQTT.Client(mqtt_server, mqtt_port, clientID);
  console.log(clientID);
  client.onMessageArrived = onMessageArrived;
  client.onMessageArrived = onMessageArrived;
  client.connect({ onSuccess: onConnect });
  // document.getElementById("submsg").innerHTML = "Trying to connect...";
}

function onConnect() {
  console.log("Conectado");
  client.subscribe(mqtt_destname);
  // document.getElementById("submsg").innerHTML = "New connection made...";
  // document.getElementById("submsg").innerHTML = "Subscribing to topic: " + mqtt_destname + " ...";
}

function onMessageArrived(message) {
  var result = mqtt_destname + " : " + message.payloadString + "";
  // document.getElementById("submsg").innerHTML = result;
  console.log(mqtt_destname);
  console.log(message.payloadString.toString());
  renderLeic(message.payloadString.toString());
}
