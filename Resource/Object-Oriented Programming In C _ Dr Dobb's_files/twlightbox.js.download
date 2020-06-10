/*****************************
 * NextGen - JQuery Plugin 
 */

/**
 * Check for all the requirements to run this plugin, if something is missing alert the users
 */
function ngCheckRequirements(){
	// make sure md5 script included
	var currentLocation = document.location.href;
	if(currentLocation.match(/cookies=no/)){
		alert('This site requires cookies so we can maintain your login sessions. Please enable cookies within your browser settings.');
		exit();
	}
		
	if(typeof window.hex_md5 != 'function'){
		alert("NextGen.js: MD5 method hex_md5() not found. Please include md5 script.");
		exit();
	}
}

/**
 * The lightbox class
 */
function TWLightBox(width, height, content){
	
	this.width = null;
	this.height = null;
	this.lightboxPanel = null;
	this.lightboxOverlay = null;
	this.closeButton = null;
	this.backgroundClickable = true;
	this.closeCallback = null;
	this.options = {};
	var lb = this;	
	
	this.showError = function(htmlContent){
		if(this.lightboxPanel != null){
			if(htmlContent == undefined){
				htmlContent = 'Oops, something has gone wrong. Please contact administrator.';
			}
			if($('#ngLoadingScreen').lenght != undefined){
				$('#ngLoadingScreen').text(htmlContent);
			}
			else{
				this.close();
				this.open();
				var domain = document.domain.split('.').reverse()[1];
				this.lightboxPanel.html('<div id="ngErrorScreen" class="'+domain+'">'+htmlContent+'</div>');
			}			
		}		
		this.update();
	}
	
	this.showLoader = function(htmlContent){
		if(this.lightboxPanel != null){
			if(htmlContent == undefined){
				htmlContent = 'Loading please wait...';
			}
			var domain = document.domain.split('.').reverse()[1];
			this.lightboxPanel.html('<div id="ngLoadingScreen" class="'+domain+'">'+htmlContent+'</div>');
		}		
		this.update();
	}
	
	this.setHtml = function(htmlContent, title){
		if(this.lightboxPanel != null){
			if(title == undefined){
				title = 'Techweb';
			}
			className = '';
			if(title.match('Registration') || title.match('Update Profile')){
				className = 'register';
			}
			else if(title.match('Login')){
				className = 'login';
			}
			var html = '<div id="topLoginHeader"><div class="nextGenContainer_title">'+title+'</div><div class="nextGenContainer_closeButton"><div id="nextGenContainer_closeButton_inner" onclick="NextGen.close();"></div></div></div><div id="nextGenLoginContainer" class="'+className+'"><div id="nextGenContainer" class="'+className+'">'+htmlContent+'</div></div><div class="emptyFix" id="nextGenFooterContainer"></div>';
			this.lightboxPanel.html(html);
		}
		this.update();
	};

	this.setSize = function(width,height){
		this.width = width;
		this.height = height;
		if(this.width !== null){
			this.lightboxPanel.css('width',this.width+'px');
		}
		if(this.height !== null){
			this.lightboxPanel.css('height',this.height+'px');
		}
		this.update();
	};

	this.setupLightBox = function() {	
		if($('#TWLightBoxOverlay').length == 0){
			$('body').append('<div id="TWLightBoxOverlay"></div>');
		}
		this.lightboxOverlay = $('#TWLightBoxOverlay');
		//todo: adjustable background
		this.lightboxOverlay.css('background','none repeat scroll 0 0 #000000');
		// set the opacity
		this.lightboxOverlay.css('opacity','0.9');
		this.lightboxOverlay.css('filter','alpha(opacity=90)');
		this.lightboxOverlay.css('position','fixed').css('top','0px').css('left','0px');
		this.lightboxOverlay.css('width','100%').css('height','100%').css('z-index','1000');
		this.lightboxOverlay.hide();
		this.lightboxOverlay.click(function(){
			if(thisbox.backgroundClickable){
				thisbox.close();
			}
			if(lb.closeCallback){
				lb.closeCallback();
			}
		});
	};

	this.update = function(){
		var marginXOffset = -this.lightboxPanel.outerWidth()/2;
		this.lightboxPanel.css('margin-left',marginXOffset+'px');
		var marginYOffset = -this.lightboxPanel.outerHeight()/2;		
		this.lightboxPanel.css('margin-top', '-250px');
	};

	this.close = function(){
		if(this.lightboxPanel && this.lightboxOverlay){
			this.lightboxOverlay.hide();
			this.lightboxPanel.html('');
			this.lightboxPanel.hide();
			$("body").css("overflow", "auto");	
		}
	};

	this.open = function(){
		if(this.lightboxPanel && this.lightboxOverlay){
			this.lightboxOverlay.show();
			this.lightboxPanel.show();
			$("body").css("overflow", "hidden");	
		}
	};

	this.setupLightBoxPanel = function(content){
		if($('#TWLightBoxPanel').length == 0){
			var domain = document.domain.split('.').reverse()[1];
			$('body').append('<div id="TWLightBoxPanel" class="'+domain+'"></div>');
		}
		this.lightboxPanel = $('#TWLightBoxPanel');
		this.setSize(width,height);
		this.lightboxPanel.css('position','fixed').hide();

		this.lightboxPanel.css('top','50%').css('left','50%').css('z-index','6000000');		
		this.lightboxPanel.hide();	
		if(typeof(content) !== "undefined"){
			this.setHtml(content);
		}		
		this.update();
	};

	// constructor 
	var thisbox = this;
	
	this.setupLightBox();

	if(width)
		this.width = width;
	if(height)
		this.height = height;

	this.setupLightBoxPanel(content);	
}

/********************** JQUERY PLUGIN ENDS ************************/