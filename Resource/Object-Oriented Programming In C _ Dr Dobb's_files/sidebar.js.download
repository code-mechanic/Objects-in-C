/*
 * sidebar.js
 * 23 Oct 08
 *
 * This script builds carousel interaction for the sidebar of the InformationWeek home page.
 * 
 */

$(document).ready(function() {
	
	// attach interaction to video carousel controls on document load
	sidebarAttachControls (".video");
	sidebarAttachControls (".mostpopular");
	sidebarAttachControls (".search");

}
);

function sidebarAttachControls (target) {
	// this function sets up each carousel
	
	// hide all slides but the first, just in case
	$(target + " .box_wrap:gt(0)").css("display","none"); 
	
	// set up previous/next buttons
	$(target + ' .controls a.slide_left').click(function(){ sidebarJump(target, "prev"); return false });
	$(target + ' .controls a.slide_right').click(function(){ sidebarJump(target, "next"); return false });
	
	// set up indicator dots, if they exist
	$(target + ' .controls img').each(
		function(i) { 
			$(this).click( function() { sidebarJump(target, i); } );
			}
		);
	
	// set up tabs, if they exist
	$(target + ' .tab_controls a').each(
		function(i) { 
			$(this).click( function() { sidebarJump(target, i); return false } );
			}
		);
	
}

function sidebarJump (target,action) {
	
	// Not fully abstracted; this is a quickie.
	// Preferences must be reset here if HTML of carousel changes.
	
	var numFrames = 2;
	var tabTarget = target + " .tab_controls a";
	var activeTabClass = "current";
	var indicatorTarget = target + " .tab_controls img";
	var activeIndicatorSrc = "images/slide_dot_red.jpg";
	var inactiveIndicatorSrc = "images/slide_dot_gray.jpg";
	
	// determine which frame is active
	var activeFrame = 0;
	$(target + " .box_wrap").each(
		function(i) {
			if ($(this).css('display') != "none") { activeFrame = i }
		});
	
	// figure out what frame to show next
	var nextFrame = 1;
	if (action == "next") { nextFrame = (activeFrame + 1) % numFrames; };
	if (action == "prev") {	nextFrame = (activeFrame == 0) ? numFrames - 1 : Math.abs( (activeFrame - 1) % numFrames); }
	if (action <= numFrames) { nextFrame = action; }
	
	// alert ("active: " + activeFrame + ", next: " + nextFrame);
	
	// actually do it
 	if (activeFrame != nextFrame) {
		
		$(target + " .box_wrap:eq(" + activeFrame + ")").css('display', 'none');
		$(target + " .box_wrap:eq(" + nextFrame + ")").css('display', 'block');
	
		// change tabs if they exist
		$(tabTarget + ":eq(" + activeFrame + ")").removeClass(activeTabClass);
		$(tabTarget + ":eq(" + nextFrame + ")").addClass(activeTabClass);
		
		// change indicator dots if they exist
		$(indicatorTarget + ":eq(" + activeFrame + ")").attr("src",inactiveIndicatorSrc);
		$(indicatorTarget + ":eq(" + nextFrame + ")").attr("src",activeIndicatorSrc);
		
	};
		
};
