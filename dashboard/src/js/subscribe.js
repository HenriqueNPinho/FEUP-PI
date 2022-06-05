mqtt_server = "broker.mqttdashboard.com";
mqtt_port = 8000;
mqtt_destname = "secretaria";

function sub_mqtt_msg() {
  client = new Paho.MQTT.Client(mqtt_server, mqtt_port, "");
  client.onMessageArrived = onMessageArrived;
  client.onMessageArrived = onMessageArrived;
  client.connect({ onSuccess: onConnect });
  document.getElementById("submsg").innerHTML = "Trying to connect...";
}

function onConnect() {
  document.getElementById("submsg").innerHTML = "New connection made...";
  client.subscribe(mqtt_destname);
  document.getElementById("submsg").innerHTML = "Subscribing to topic: " + mqtt_destname + " ...";
}

function onMessageArrived(message) {
  var result = mqtt_destname + " : " + message.payloadString + "";
  document.getElementById("submsg").innerHTML = result;
  console.log(mqtt_destname);
  renderLeic(message.payloadString.toString());
}
