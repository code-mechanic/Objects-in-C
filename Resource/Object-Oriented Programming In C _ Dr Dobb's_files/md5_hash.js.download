(function(b)
    {
        var d={
            vertical:false,
            rtl:false,
            start:1,
            offset:1,
            size:null,
            scroll:3,
            visible:null,
            animation:"normal",
            easing:"swing",
            auto:0,
            wrap:null,
            initCallback:null,
            reloadCallback:null,
            itemLoadCallback:null,
            itemFirstInCallback:null,
            itemFirstOutCallback:null,
            itemLastInCallback:null,
            itemLastOutCallback:null,
            itemVisibleInCallback:null,
            itemVisibleOutCallback:null,
            buttonNextHTML:"<div></div>",
            buttonPrevHTML:"<div></div>",
            buttonNextEvent:"click",
            buttonPrevEvent:"click",
            buttonNextCallback:null,
            buttonPrevCallback:null,
            itemFallbackDimension:null
        },a=false;b(window).bind("load.jcarousel",function(){
            a=true
            });b.jcarousel=function(e,g){
            this.options=b.extend({},d,g||{});this.autoStopped=this.locked=false;this.buttonPrevState=this.buttonNextState=this.buttonPrev=this.buttonNext=this.list=this.clip=this.container=null;if(!g||g.rtl===void 0)this.options.rtl=(b(e).attr("dir")||b("html").attr("dir")||"").toLowerCase()=="rtl";this.wh=!this.options.vertical?"width":"height";this.lt=!this.options.vertical?this.options.rtl?"right":
            "left":"top";for(var f="",c=e.className.split(" "),k=0;k<c.length;k++)if(c[k].indexOf("jcarousel-skin")!=-1){
                b(e).removeClass(c[k]);f=c[k];break
            }if(e.nodeName.toUpperCase()=="UL"||e.nodeName.toUpperCase()=="OL")if(this.list=b(e),this.container=this.list.parent(),this.container.hasClass("jcarousel-clip")){
                if(!this.container.parent().hasClass("jcarousel-container"))this.container=this.container.wrap("<div></div>");this.container=this.container.parent()
                }else{
                if(!this.container.hasClass("jcarousel-container"))this.container=
                    this.list.wrap("<div></div>").parent()
                    }else this.container=b(e),this.list=this.container.find("ul,ol").eq(0);f!==""&&this.container.parent()[0].className.indexOf("jcarousel-skin")==-1&&this.container.wrap('<div class=" '+f+'"></div>');this.clip=this.list.parent();if(!this.clip.length||!this.clip.hasClass("jcarousel-clip"))this.clip=this.list.wrap("<div></div>").parent();this.buttonNext=b(".jcarousel-next",this.container);if(this.buttonNext.size()===0&&this.options.buttonNextHTML!==null)this.buttonNext=
                this.clip.after(this.options.buttonNextHTML).next();this.buttonNext.addClass(this.className("jcarousel-next"));this.buttonPrev=b(".jcarousel-prev",this.container);if(this.buttonPrev.size()===0&&this.options.buttonPrevHTML!==null)this.buttonPrev=this.clip.after(this.options.buttonPrevHTML).next();this.buttonPrev.addClass(this.className("jcarousel-prev"));this.clip.addClass(this.className("jcarousel-clip")).css({
                overflow:"hidden",
                position:"relative"
            });this.list.addClass(this.className("jcarousel-list")).css({
                overflow:"hidden",
                position:"relative",
                top:0,
                margin:0,
                padding:0
            }).css(this.options.rtl?"right":"left",0);this.container.addClass(this.className("jcarousel-container")).css({
                position:"relative"
            });!this.options.vertical&&this.options.rtl&&this.container.addClass("jcarousel-direction-rtl").attr("dir","rtl");var h=this.options.visible!==null?Math.ceil(this.clipping()/this.options.visible):null,f=this.list.children("li"),j=this;if(f.size()>0){
                var m=0,o=this.options.offset;f.each(function(){
                    j.format(this,o++);m+=j.dimension(this,
                        h)
                    });this.list.css(this.wh,m+100+"px");if(!g||g.size===void 0)this.options.size=f.size()
                    }this.container.css("display","block");this.buttonNext.css("display","block");this.buttonPrev.css("display","block");this.funcNext=function(){
                j.next()
                };this.funcPrev=function(){
                j.prev()
                };this.funcResize=function(){
                j.reload()
                };this.options.initCallback!==null&&this.options.initCallback(this,"init");!a&&b.browser.safari?(this.buttons(false,false),b(window).bind("load.jcarousel",function(){
                j.setup()
                })):this.setup()
            };
        var c=b.jcarousel;c.fn=c.prototype={
            jcarousel:"0.2.7"
        };c.fn.extend=c.extend=b.extend;c.fn.extend({
            setup:function(){
                this.prevLast=this.prevFirst=this.last=this.first=null;this.animating=false;this.tail=this.timer=null;this.inTail=false;if(!this.locked){
                    this.list.css(this.lt,this.pos(this.options.offset)+"px");var e=this.pos(this.options.start,true);this.prevFirst=this.prevLast=null;this.animate(e,false);b(window).unbind("resize.jcarousel",this.funcResize).bind("resize.jcarousel",this.funcResize)
                    }
                },
            reset:function(){
                this.list.empty();this.list.css(this.lt,"0px");this.list.css(this.wh,"10px");this.options.initCallback!==null&&this.options.initCallback(this,"reset");this.setup()
                },
            reload:function(){
                this.tail!==null&&this.inTail&&this.list.css(this.lt,c.intval(this.list.css(this.lt))+this.tail);this.tail=null;this.inTail=false;this.options.reloadCallback!==null&&this.options.reloadCallback(this);if(this.options.visible!==null){
                    var e=this,b=Math.ceil(this.clipping()/this.options.visible),a=0,d=0;
                    this.list.children("li").each(function(c){
                        a+=e.dimension(this,b);c+1<e.first&&(d=a)
                        });this.list.css(this.wh,a+"px");this.list.css(this.lt,-d+"px")
                    }this.scroll(this.first,false)
                },
            lock:function(){
                this.locked=true;this.buttons()
                },
            unlock:function(){
                this.locked=false;this.buttons()
                },
            size:function(e){
                if(e!==void 0)this.options.size=e,this.locked||this.buttons();return this.options.size
                },
            has:function(e,b){
                if(b===void 0||!b)b=e;if(this.options.size!==null&&b>this.options.size)b=this.options.size;for(var a=
                    e;a<=b;a++){
                    var c=this.get(a);if(!c.length||c.hasClass("jcarousel-item-placeholder"))return false
                        }return true
                },
            get:function(e){
                return b(".jcarousel-item-"+e,this.list)
                },
            add:function(e,a){
                var f=this.get(e),d=0,k=b(a);if(f.length===0)for(var h,j=c.intval(e),f=this.create(e);;){
                    if(h=this.get(--j),j<=0||h.length){
                        j<=0?this.list.prepend(f):h.after(f);break
                    }
                    }else d=this.dimension(f);k.get(0).nodeName.toUpperCase()=="LI"?(f.replaceWith(k),f=k):f.empty().append(a);this.format(f.removeClass(this.className("jcarousel-item-placeholder")),
                    e);k=this.options.visible!==null?Math.ceil(this.clipping()/this.options.visible):null;d=this.dimension(f,k)-d;e>0&&e<this.first&&this.list.css(this.lt,c.intval(this.list.css(this.lt))-d+"px");this.list.css(this.wh,c.intval(this.list.css(this.wh))+d+"px");return f
                },
            remove:function(e){
                var b=this.get(e);if(b.length&&!(e>=this.first&&e<=this.last)){
                    var a=this.dimension(b);e<this.first&&this.list.css(this.lt,c.intval(this.list.css(this.lt))+a+"px");b.remove();this.list.css(this.wh,c.intval(this.list.css(this.wh))-
                        a+"px")
                    }
                },
            next:function(){
                this.tail!==null&&!this.inTail?this.scrollTail(false):this.scroll((this.options.wrap=="both"||this.options.wrap=="last")&&this.options.size!==null&&this.last==this.options.size?1:this.first+this.options.scroll)
                },
            prev:function(){
                this.tail!==null&&this.inTail?this.scrollTail(true):this.scroll((this.options.wrap=="both"||this.options.wrap=="first")&&this.options.size!==null&&this.first==1?this.options.size:this.first-this.options.scroll)
                },
            scrollTail:function(e){
                if(!this.locked&&
                    !this.animating&&this.tail){
                    this.pauseAuto();var b=c.intval(this.list.css(this.lt)),b=!e?b-this.tail:b+this.tail;this.inTail=!e;this.prevFirst=this.first;this.prevLast=this.last;this.animate(b)
                    }
                },
            scroll:function(e,b){
                !this.locked&&!this.animating&&(this.pauseAuto(),this.animate(this.pos(e),b))
                },
            pos:function(e,b){
                var a=c.intval(this.list.css(this.lt));if(this.locked||this.animating)return a;this.options.wrap!="circular"&&(e=e<1?1:this.options.size&&e>this.options.size?this.options.size:e);for(var d=
                    this.first>e,k=this.options.wrap!="circular"&&this.first<=1?1:this.first,h=d?this.get(k):this.get(this.last),j=d?k:k-1,m=null,o=0,r=false,s=0;d?--j>=e:++j<e;){
                    m=this.get(j);r=!m.length;if(m.length===0&&(m=this.create(j).addClass(this.className("jcarousel-item-placeholder")),h[d?"before":"after"](m),this.first!==null&&this.options.wrap=="circular"&&this.options.size!==null&&(j<=0||j>this.options.size)))h=this.get(this.index(j)),h.length&&(m=this.add(j,h.clone(true)));h=m;s=this.dimension(m);r&&(o+=
                        s);if(this.first!==null&&(this.options.wrap=="circular"||j>=1&&(this.options.size===null||j<=this.options.size)))a=d?a+s:a-s
                        }for(var k=this.clipping(),w=[],u=0,t=0,h=this.get(e-1),j=e;++u;){
                    m=this.get(j);r=!m.length;if(m.length===0&&(m=this.create(j).addClass(this.className("jcarousel-item-placeholder")),h.length===0?this.list.prepend(m):h[d?"before":"after"](m),this.first!==null&&this.options.wrap=="circular"&&this.options.size!==null&&(j<=0||j>this.options.size)))h=this.get(this.index(j)),h.length&&
                        (m=this.add(j,h.clone(true)));h=m;s=this.dimension(m);if(s===0)throw Error("jCarousel: No width/height set for items. This will cause an infinite loop. Aborting...");this.options.wrap!="circular"&&this.options.size!==null&&j>this.options.size?w.push(m):r&&(o+=s);t+=s;if(t>=k)break;j++
                }for(m=0;m<w.length;m++)w[m].remove();o>0&&(this.list.css(this.wh,this.dimension(this.list)+o+"px"),d&&(a-=o,this.list.css(this.lt,c.intval(this.list.css(this.lt))-o+"px")));o=e+u-1;if(this.options.wrap!="circular"&&
                    this.options.size&&o>this.options.size)o=this.options.size;if(j>o){
                    u=0;j=o;for(t=0;++u;){
                        m=this.get(j--);if(!m.length)break;t+=this.dimension(m);if(t>=k)break
                    }
                    }j=o-u+1;this.options.wrap!="circular"&&j<1&&(j=1);if(this.inTail&&d)a+=this.tail,this.inTail=false;this.tail=null;if(this.options.wrap!="circular"&&o==this.options.size&&o-u+1>=1&&(d=c.margin(this.get(o),!this.options.vertical?"marginRight":"marginBottom"),t-d>k))this.tail=t-k-d;if(b&&e===this.options.size&&this.tail)a-=this.tail,this.inTail=
                    true;for(;e-- >j;)a+=this.dimension(this.get(e));this.prevFirst=this.first;this.prevLast=this.last;this.first=j;this.last=o;return a
                },
            animate:function(e,b){
                if(!this.locked&&!this.animating){
                    this.animating=true;var a=this,c=function(){
                        a.animating=false;e===0&&a.list.css(a.lt,0);!a.autoStopped&&(a.options.wrap=="circular"||a.options.wrap=="both"||a.options.wrap=="last"||a.options.size===null||a.last<a.options.size||a.last==a.options.size&&a.tail!==null&&!a.inTail)&&a.startAuto();a.buttons();a.notify("onAfterAnimation");
                        if(a.options.wrap=="circular"&&a.options.size!==null)for(var b=a.prevFirst;b<=a.prevLast;b++)b!==null&&!(b>=a.first&&b<=a.last)&&(b<1||b>a.options.size)&&a.remove(b)
                            };this.notify("onBeforeAnimation");!this.options.animation||b===false?(this.list.css(this.lt,e+"px"),c()):this.list.animate(!this.options.vertical?this.options.rtl?{
                        right:e
                    }:{
                        left:e
                    }:{
                        top:e
                    },this.options.animation,this.options.easing,c)
                    }
                },
            startAuto:function(b){
                if(b!==void 0)this.options.auto=b;if(this.options.auto===0)return this.stopAuto();
                if(this.timer===null){
                    this.autoStopped=false;var a=this;this.timer=window.setTimeout(function(){
                        a.next()
                        },this.options.auto*1E3)
                    }
                },
            stopAuto:function(){
                this.pauseAuto();this.autoStopped=true
                },
            pauseAuto:function(){
                if(this.timer!==null)window.clearTimeout(this.timer),this.timer=null
                    },
            buttons:function(b,a){
                if(b==null&&(b=!this.locked&&this.options.size!==0&&(this.options.wrap&&this.options.wrap!="first"||this.options.size===null||this.last<this.options.size),!this.locked&&(!this.options.wrap||this.options.wrap==
                    "first")&&this.options.size!==null&&this.last>=this.options.size))b=this.tail!==null&&!this.inTail;if(a==null&&(a=!this.locked&&this.options.size!==0&&(this.options.wrap&&this.options.wrap!="last"||this.first>1),!this.locked&&(!this.options.wrap||this.options.wrap=="last")&&this.options.size!==null&&this.first==1))a=this.tail!==null&&this.inTail;var c=this;this.buttonNext.size()>0?(this.buttonNext.unbind(this.options.buttonNextEvent+".jcarousel",this.funcNext),b&&this.buttonNext.bind(this.options.buttonNextEvent+
                    ".jcarousel",this.funcNext),this.buttonNext[b?"removeClass":"addClass"](this.className("jcarousel-next-disabled")).attr("disabled",b?false:true),this.options.buttonNextCallback!==null&&this.buttonNext.data("jcarouselstate")!=b&&this.buttonNext.each(function(){
                    c.options.buttonNextCallback(c,this,b)
                    }).data("jcarouselstate",b)):this.options.buttonNextCallback!==null&&this.buttonNextState!=b&&this.options.buttonNextCallback(c,null,b);this.buttonPrev.size()>0?(this.buttonPrev.unbind(this.options.buttonPrevEvent+
                    ".jcarousel",this.funcPrev),a&&this.buttonPrev.bind(this.options.buttonPrevEvent+".jcarousel",this.funcPrev),this.buttonPrev[a?"removeClass":"addClass"](this.className("jcarousel-prev-disabled")).attr("disabled",a?false:true),this.options.buttonPrevCallback!==null&&this.buttonPrev.data("jcarouselstate")!=a&&this.buttonPrev.each(function(){
                    c.options.buttonPrevCallback(c,this,a)
                    }).data("jcarouselstate",a)):this.options.buttonPrevCallback!==null&&this.buttonPrevState!=a&&this.options.buttonPrevCallback(c,
                    null,a);this.buttonNextState=b;this.buttonPrevState=a
                },
            notify:function(b){
                var a=this.prevFirst===null?"init":this.prevFirst<this.first?"next":"prev";this.callback("itemLoadCallback",b,a);this.prevFirst!==this.first&&(this.callback("itemFirstInCallback",b,a,this.first),this.callback("itemFirstOutCallback",b,a,this.prevFirst));this.prevLast!==this.last&&(this.callback("itemLastInCallback",b,a,this.last),this.callback("itemLastOutCallback",b,a,this.prevLast));this.callback("itemVisibleInCallback",b,
                    a,this.first,this.last,this.prevFirst,this.prevLast);this.callback("itemVisibleOutCallback",b,a,this.prevFirst,this.prevLast,this.first,this.last)
                },
            callback:function(a,c,f,d,k,h,j){
                if(!(this.options[a]==null||typeof this.options[a]!="object"&&c!="onAfterAnimation")){
                    var m=typeof this.options[a]=="object"?this.options[a][c]:this.options[a];if(b.isFunction(m)){
                        var o=this;if(d===void 0)m(o,f,c);else if(k===void 0)this.get(d).each(function(){
                            m(o,this,d,f,c)
                            });else for(var a=function(a){
                            o.get(a).each(function(){
                                m(o,
                                    this,a,f,c)
                                })
                            },r=d;r<=k;r++)r!==null&&!(r>=h&&r<=j)&&a(r)
                            }
                    }
                },
            create:function(a){
                return this.format("<li></li>",a)
                },
            format:function(a,c){
                for(var a=b(a),f=a.get(0).className.split(" "),d=0;d<f.length;d++)f[d].indexOf("jcarousel-")!=-1&&a.removeClass(f[d]);a.addClass(this.className("jcarousel-item")).addClass(this.className("jcarousel-item-"+c)).css({
                    "float":this.options.rtl?"right":"left",
                    "list-style":"none"
                }).attr("jcarouselindex",c);return a
                },
            className:function(a){
                return a+" "+a+(!this.options.vertical?
                    "-horizontal":"-vertical")
                },
            dimension:function(a,g){
                var f=a.jquery!==void 0?a[0]:a,d=!this.options.vertical?(f.offsetWidth||c.intval(this.options.itemFallbackDimension))+c.margin(f,"marginLeft")+c.margin(f,"marginRight"):(f.offsetHeight||c.intval(this.options.itemFallbackDimension))+c.margin(f,"marginTop")+c.margin(f,"marginBottom");if(g==null||d==g)return d;d=!this.options.vertical?g-c.margin(f,"marginLeft")-c.margin(f,"marginRight"):g-c.margin(f,"marginTop")-c.margin(f,"marginBottom");b(f).css(this.wh,
                    d+"px");return this.dimension(f)
                },
            clipping:function(){
                return!this.options.vertical?this.clip[0].offsetWidth-c.intval(this.clip.css("borderLeftWidth"))-c.intval(this.clip.css("borderRightWidth")):this.clip[0].offsetHeight-c.intval(this.clip.css("borderTopWidth"))-c.intval(this.clip.css("borderBottomWidth"))
                },
            index:function(a,b){
                if(b==null)b=this.options.size;return Math.round(((a-1)/b-Math.floor((a-1)/b))*b)+1
                }
            });c.extend({
            defaults:function(a){
                return b.extend(d,a||{})
                },
            margin:function(a,g){
                if(!a)return 0;
                var f=a.jquery!==void 0?a[0]:a;if(g=="marginRight"&&b.browser.safari){
                    var d={
                        display:"block",
                        "float":"none",
                        width:"auto"
                    },k,h;b.swap(f,d,function(){
                        k=f.offsetWidth
                        });d.marginRight=0;b.swap(f,d,function(){
                        h=f.offsetWidth
                        });return h-k
                    }return c.intval(b.css(f,g))
                },
            intval:function(a){
                a=parseInt(a,10);return isNaN(a)?0:a
                }
            });b.fn.jcarousel=function(a){
            if(typeof a=="string"){
                var g=b(this).data("jcarousel"),f=Array.prototype.slice.call(arguments,1);return g[a].apply(g,f)
                }else return this.each(function(){
                b(this).data("jcarousel",
                    new c(this,a))
                })
            }
        })(jQuery);

jQuery.fn.twFontSprite=function(b,d,a){
    this.each(function(){
        d==void 0&&(d="large");var c=$(this).html(),c=$.trim(c),e=$(this);$.getJSON(b+"/font.json",function(g){
            g[d]==void 0&&(d="large");var g=g[d],f=c.split(""),i;i=".fontSprite { background: url("+b+"/"+g.file+") no-repeat; display: inline-block; } .char_space { display: inline-block; }";a!=void 0&&(i=i+"\n.fontSprite { margin-right: "+a+"px; }");e.html("");for(var k in f)if(f[k]==" ")e.append('<span class="char_space" style="width: 10px; height: 10px;"></span>');else if(g[f[k]]!=
                void 0){
                var h=g[f[k]];e.append('<span class="fontSprite char_'+f[k]+'" style="width: '+h.w+"px; height: "+h.h+"px; background-position: -"+h.x+"px "+h.y+'px"></span>')
                }e.prepend('<style type="text/css">\n'+i+"\n</style>")
            })
        });return this
    };
   var hexcase=0;
   function hex_md5(b){
    return rstr2hex(rstr_md5(str2rstr_utf8(b)))
   }
   function hex_hmac_md5(b,d){
    return rstr2hex(rstr_hmac_md5(str2rstr_utf8(b),str2rstr_utf8(d)))
   }
   function md5_vm_test(){
    return hex_md5("abc").toLowerCase()=="900150983cd24fb0d6963f7d28e17f72"
   }
   function rstr_md5(b){
    return binl2rstr(binl_md5(rstr2binl(b),b.length*8))
    }function rstr_hmac_md5(b,d){
    var a=rstr2binl(b);a.length>16&&(a=binl_md5(a,b.length*8));for(var c=Array(16),e=Array(16),g=0;g<16;g++)c[g]=a[g]^909522486,e[g]=a[g]^1549556828;a=binl_md5(c.concat(rstr2binl(d)),512+d.length*8);return binl2rstr(binl_md5(e.concat(a),640))
    }
function rstr2hex(b){
    for(var d=hexcase?"0123456789ABCDEF":"0123456789abcdef",a="",c,e=0;e<b.length;e++)c=b.charCodeAt(e),a+=d.charAt(c>>>4&15)+d.charAt(c&15);return a
    }
function str2rstr_utf8(b){
    for(var d="",a=-1,c,e;++a<b.length;)c=b.charCodeAt(a),e=a+1<b.length?b.charCodeAt(a+1):0,55296<=c&&c<=56319&&56320<=e&&e<=57343&&(c=65536+((c&1023)<<10)+(e&1023),a++),c<=127?d+=String.fromCharCode(c):c<=2047?d+=String.fromCharCode(192|c>>>6&31,128|c&63):c<=65535?d+=String.fromCharCode(224|c>>>12&15,128|c>>>6&63,128|c&63):c<=2097151&&(d+=String.fromCharCode(240|c>>>18&7,128|c>>>12&63,128|c>>>6&63,128|c&63));return d
    }
function rstr2binl(b){
    for(var d=Array(b.length>>2),a=0;a<d.length;a++)d[a]=0;for(a=0;a<b.length*8;a+=8)d[a>>5]|=(b.charCodeAt(a/8)&255)<<a%32;return d
    }function binl2rstr(b){
    for(var d="",a=0;a<b.length*32;a+=8)d+=String.fromCharCode(b[a>>5]>>>a%32&255);return d
    }
function binl_md5(b,d){
    b[d>>5]|=128<<d%32;b[(d+64>>>9<<4)+14]=d;for(var a=1732584193,c=-271733879,e=-1732584194,g=271733878,f=0;f<b.length;f+=16)var i=a,k=c,h=e,j=g,a=md5_ff(a,c,e,g,b[f+0],7,-680876936),g=md5_ff(g,a,c,e,b[f+1],12,-389564586),e=md5_ff(e,g,a,c,b[f+2],17,606105819),c=md5_ff(c,e,g,a,b[f+3],22,-1044525330),a=md5_ff(a,c,e,g,b[f+4],7,-176418897),g=md5_ff(g,a,c,e,b[f+5],12,1200080426),e=md5_ff(e,g,a,c,b[f+6],17,-1473231341),c=md5_ff(c,e,g,a,b[f+7],22,-45705983),a=md5_ff(a,c,e,g,b[f+8],7,
        1770035416),g=md5_ff(g,a,c,e,b[f+9],12,-1958414417),e=md5_ff(e,g,a,c,b[f+10],17,-42063),c=md5_ff(c,e,g,a,b[f+11],22,-1990404162),a=md5_ff(a,c,e,g,b[f+12],7,1804603682),g=md5_ff(g,a,c,e,b[f+13],12,-40341101),e=md5_ff(e,g,a,c,b[f+14],17,-1502002290),c=md5_ff(c,e,g,a,b[f+15],22,1236535329),a=md5_gg(a,c,e,g,b[f+1],5,-165796510),g=md5_gg(g,a,c,e,b[f+6],9,-1069501632),e=md5_gg(e,g,a,c,b[f+11],14,643717713),c=md5_gg(c,e,g,a,b[f+0],20,-373897302),a=md5_gg(a,c,e,g,b[f+5],5,-701558691),g=md5_gg(g,a,c,e,b[f+
        10],9,38016083),e=md5_gg(e,g,a,c,b[f+15],14,-660478335),c=md5_gg(c,e,g,a,b[f+4],20,-405537848),a=md5_gg(a,c,e,g,b[f+9],5,568446438),g=md5_gg(g,a,c,e,b[f+14],9,-1019803690),e=md5_gg(e,g,a,c,b[f+3],14,-187363961),c=md5_gg(c,e,g,a,b[f+8],20,1163531501),a=md5_gg(a,c,e,g,b[f+13],5,-1444681467),g=md5_gg(g,a,c,e,b[f+2],9,-51403784),e=md5_gg(e,g,a,c,b[f+7],14,1735328473),c=md5_gg(c,e,g,a,b[f+12],20,-1926607734),a=md5_hh(a,c,e,g,b[f+5],4,-378558),g=md5_hh(g,a,c,e,b[f+8],11,-2022574463),e=md5_hh(e,g,a,c,b[f+
        11],16,1839030562),c=md5_hh(c,e,g,a,b[f+14],23,-35309556),a=md5_hh(a,c,e,g,b[f+1],4,-1530992060),g=md5_hh(g,a,c,e,b[f+4],11,1272893353),e=md5_hh(e,g,a,c,b[f+7],16,-155497632),c=md5_hh(c,e,g,a,b[f+10],23,-1094730640),a=md5_hh(a,c,e,g,b[f+13],4,681279174),g=md5_hh(g,a,c,e,b[f+0],11,-358537222),e=md5_hh(e,g,a,c,b[f+3],16,-722521979),c=md5_hh(c,e,g,a,b[f+6],23,76029189),a=md5_hh(a,c,e,g,b[f+9],4,-640364487),g=md5_hh(g,a,c,e,b[f+12],11,-421815835),e=md5_hh(e,g,a,c,b[f+15],16,530742520),c=md5_hh(c,e,g,
        a,b[f+2],23,-995338651),a=md5_ii(a,c,e,g,b[f+0],6,-198630844),g=md5_ii(g,a,c,e,b[f+7],10,1126891415),e=md5_ii(e,g,a,c,b[f+14],15,-1416354905),c=md5_ii(c,e,g,a,b[f+5],21,-57434055),a=md5_ii(a,c,e,g,b[f+12],6,1700485571),g=md5_ii(g,a,c,e,b[f+3],10,-1894986606),e=md5_ii(e,g,a,c,b[f+10],15,-1051523),c=md5_ii(c,e,g,a,b[f+1],21,-2054922799),a=md5_ii(a,c,e,g,b[f+8],6,1873313359),g=md5_ii(g,a,c,e,b[f+15],10,-30611744),e=md5_ii(e,g,a,c,b[f+6],15,-1560198380),c=md5_ii(c,e,g,a,b[f+13],21,1309151649),a=md5_ii(a,
        c,e,g,b[f+4],6,-145523070),g=md5_ii(g,a,c,e,b[f+11],10,-1120210379),e=md5_ii(e,g,a,c,b[f+2],15,718787259),c=md5_ii(c,e,g,a,b[f+9],21,-343485551),a=safe_add(a,i),c=safe_add(c,k),e=safe_add(e,h),g=safe_add(g,j);return[a,c,e,g]
    }function md5_cmn(b,d,a,c,e,g){
    return safe_add(bit_rol(safe_add(safe_add(d,b),safe_add(c,g)),e),a)
    }function md5_ff(b,d,a,c,e,g,f){
    return md5_cmn(d&a|~d&c,b,d,e,g,f)
    }function md5_gg(b,d,a,c,e,g,f){
    return md5_cmn(d&c|a&~c,b,d,e,g,f)
    }
function md5_hh(b,d,a,c,e,g,f){
    return md5_cmn(d^a^c,b,d,e,g,f)
    }function md5_ii(b,d,a,c,e,g,f){
    return md5_cmn(a^(d|~c),b,d,e,g,f)
    }function safe_add(b,d){
    var a=(b&65535)+(d&65535);return(b>>16)+(d>>16)+(a>>16)<<16|a&65535
    }function bit_rol(b,d){
    return b<<d|b>>>32-d
    }