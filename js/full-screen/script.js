function toggleFullScreen() {
  if (!document.fullscreenElement) {
      document.documentElement.requestFullscreen();
  } else {
    if (document.exitFullscreen) {
      document.exitFullscreen();
    }
  }
}

document.addEventListener('DOMContentLoaded', (e) => toggleFullScreen());

let btn =  document.getElementById('btn');
btn.addEventListener('click', (e) => toggleFullScreen());