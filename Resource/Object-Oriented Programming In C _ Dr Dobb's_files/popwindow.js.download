
// popwindow function for full-size illustration display

function popimage(t,title){
	var handle = window.open("","","toolbar=no,location=no,directories=no,status=no,menubar=no,resizable=yes,scrollbars=yes");
	handle.document.open();
	handle.document.write("<head>");
	handle.document.write("<title>" + title + "</title>");
	handle.document.write("<link rel=\"stylesheet\" type=\"text/css\" href=\"https://i.cmpnet.com/ddj/styles/newarticle.css\" />");
	handle.document.write("</head><body onclick=\"window.close()\">");

	handle.document.write("<div class=\"caption\" style=\"width: 100%\">");
	
	for(i = 0;i < t.parentNode.childNodes.length;i++)
		if (t.parentNode.childNodes[i].className == "caption") break;
	var s = t.parentNode.childNodes[i].innerHTML;
	s = s.slice(0,s.indexOf("[") - 1);
	
	handle.document.write(s + " [click to close window.]" + "</div>");
	handle.document.write("<img src=\"" + t.src + "\" onclick=\"window.close()\">");
	handle.document.close();
	}


