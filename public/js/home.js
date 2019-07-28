//jshint esversion: 6

/* When the user scrolls down, hide the navbar. When the user scrolls up, show the navbar */
var prevScrollpos = window.pageYOffset;

window.onscroll = function() {
  var currentScrollPos = window.pageYOffset;
  if (prevScrollpos > currentScrollPos) {
    document.getElementById("navbar").classList.add("shadow");
    document.getElementById("navbar").style.top = "0";
  } else {
    document.getElementById("navbar").classList.remove("shadow");
    document.getElementById("navbar").style.top = "-76px";
  }

  prevScrollpos = currentScrollPos;

  if (prevScrollpos === 0){
    document.getElementById("navbar").classList.remove("shadow");
  }
}
