var int = 0;

function refreshTime() {
  var dateString = new Date().toLocaleString("pt-PT", {timeZone: "Europe/Lisbon"});
  var formattedString = dateString.replace(", ", " - ");
  document.getElementById("time").innerHTML = formattedString;
}

setInterval(refreshTime, 1000);

function getData() {
  int = int + 1;
  console.log(int),
  window.addEventListener ('DOMContentLoaded', renderLeic());
}

setInterval(getData, 3000);