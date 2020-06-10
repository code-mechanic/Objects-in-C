// per http://www.addthis.com/forum/viewtopic.php?f=5&t=21252&start=0 - disable addthis.com's Flash div that's auto-written to top of page.
var addthis_config = {
	data_use_flash: false
}			

// Clear a text input field when user clicks in it
function clickclear(thisfield, defaulttext) {
	if (thisfield.value == defaulttext) {
		thisfield.value = "";
	}
}

// Restore default text to text input field if user clicks away from field leaving it unmodified
function clickrecall(thisfield, defaulttext) {
	if (thisfield.value == "") {
		thisfield.value = defaulttext;
	}
}

// Show or hide specific elements, by ID, with an A tag
function showhide(id) {
	if(document.getElementById) {
		obj = document.getElementById(id);
		if(obj.style.display == "none") {
			obj.style.display = "";
		} else {
			obj.style.display = "none";
		}
	}
}