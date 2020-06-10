function toggle() {
	var ele = document.getElementById("toggle");
	var text = document.getElementById("toggle_control");
	var button = document.getElementById("toggle_button")
	if(ele.style.display == "block") {
    	ele.style.display = "none";
		text.innerHTML = "<a href=\"javascript:toggle();\">Open</a> | Close";
		button.innerHTML = "<a href=\"javascript:toggle();\" style=\"background-position:top left\" > </a>"
  	}
	else {
		ele.style.display = "block";
		text.innerHTML = "Open | <a href=\"javascript:toggle();\">Close</a>";
		button.innerHTML = "<a href=\"javascript:toggle();\" style=\"background-position:bottom left\" > </a>"
	}
}
