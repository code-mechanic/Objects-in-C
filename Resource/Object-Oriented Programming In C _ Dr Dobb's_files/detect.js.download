var androidBranded = true;
var iphoneBranded = true;
var siteName = 'Dr.Dobbs';
 
function forumRunnerCookie () {
    var expires = new Date();
    expires.setTime(expires.getTime() + (90 * 1000 * 60 * 60 * 24));
    document.cookie = 'skip_fr_detect=false;expires=' + expires.toGMTString() + ';path=/';
}
 
function forumRunnerAndroid (opera) {
    var msg;
    var operaMsg;
    if (androidBranded && forumName != '') {
                msg = siteName + ' supports this Android device with a free App!  Tap OK to download the app, or Cancel to dismiss this prompt indefinitely.';
                operaMsg = siteName + ' supports this Android device with a free App!  Search for "' + siteName + '" in the Market to learn more about it.  Reload the page to load the normal website.';
    } else {
                msg = 'This site supports this Android device with an App!  Tap OK to read more about Dr. Dobbs for Android OS.';
                operaMsg = 'This site supports this Android device with an App!  Search for "Dr. Dobbs" in the Market to learn more about it.  Reload the page to load the normal website.';
    }
    
    if (opera) {
                forumRunnerCookie();
                alert(operaMsg);
                return;
    }
                
    if (confirm(msg)) {
                window.location = 'market://details?id=com.informationweek.editorschoice';
    } else {
                forumRunnerCookie();
    }
}
 
function forumRunnerIphone (type, opera)      {
    var operaMsg;
    var safariMsg;
 
    if (iphoneBranded) {
                operaMsg = siteName + ' supports the ' + type + ' with a free App!  Search for "Dr. Dobbs" in the App Store to learn more about it.';
                safariMsg = siteName + ' offers a free app to optimize your ' + type + ' experience.  Tap OK to download the IW ' + type + ' App, or Cancel to dismiss this prompt.';
    } else {
                operaMsg = 'This site supports the ' + type + ' with an App!  Search for "Dr. Dobbs" in the App Store to learn more about it.';
                safariMsg = 'This site supports the ' + type + ' with an App!  Tap OK to read more about Dr. Dobbs for ' + type + '.';
    }
 
    if (opera) {
                forumRunnerCookie();
                alert(operaMsg);
                return;
    }
 
    if (confirm(safariMsg)) {
                window.location = 'http://itunes.apple.com/us/app/dr.-dobbs/id439726793?mt=8';
    } else {
                forumRunnerCookie();
    }
}
 
function forumRunnerDetect () {
    if (document.cookie.indexOf('skip_fr_detect=false') == -1) {
                var agent = navigator.userAgent.toLowerCase();
                var type;
                var opera = (agent.indexOf('opera') != -1);
                var android = false;
                var iphone = false;
 
               // if (agent.indexOf('iphone') != -1) {
               //                 type = 'iPhone';
               //                 iphone = true;
               //  } else if (agent.indexOf('ipod') != -1) {
               //                 type = 'iPod Touch';
               //                 iphone = true;
                  if (agent.indexOf('ipad') != -1) {
                                type = 'iPad';
                                iphone = true;
               //}  else if (agent.indexOf('android') != -1) {
               //              android = true;
                } else {
                                return;
                }
 
                if (android) {
                                forumRunnerAndroid(opera);
                } else if (iphone) {
                                forumRunnerIphone(type, opera)
                }
    }
}
 
forumRunnerDetect();
