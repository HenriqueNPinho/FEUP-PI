function refreshTime() {
  var dateString = new Date().toLocaleString("pt-PT", {timeZone: "Europe/Lisbon"});
  var formattedString = dateString.replace(", ", " - ");
  document.getElementById("time").innerHTML = formattedString;
}

setInterval(refreshTime, 1000);