window.onload = function() {
    var date = new Date();
    document.getElementById("hour").style.transform = "rotate(" + (date.getHours() * 30 - 90)  + "deg)";
    document.getElementById("minut").style.transform = "rotate(" + (date.getMinutes() * 6 - 90)  + "deg)";
    document.getElementById("second").style.transform = "rotate(" + (date.getSeconds() * 6 - 90)  + "deg)";
}