const char JS_TABBEDCONTENT[] PROGMEM = R"=====(
;(function($,document,window,undefined){"use strict";var Tabbedcontent=function(tabcontent,options){var defaults={links:tabcontent.prev().find('a').length?tabcontent.prev().find('a'):'.tabs a',errorSelector:'.error-message',speed:false,onSwitch:false,onInit:false,currentClass:'active',tabErrorClass:'has-errors',history:true,historyOnInit:true,loop:false},firstTime=false,children=tabcontent.children(),history=window.history,loc=document.location,current=null;options=$.extend(defaults,options);if(!(options.links instanceof $)){options.links=$(options.links);}
function tabExists(tab){return Boolean(children.filter(tab).length);}
function isFirst(){return current===0;}
function isInt(num){return num%1===0;}
function isLast(){return current===children.length-1;}
function filterTab(tab){return $(this).attr('href').match(new RegExp(tab+'$'));}
function getTab(tab){if(tab instanceof $){return{tab:tab,link:options.links.eq(tab.index())};}
if(isInt(tab)){return{tab:children.eq(tab),link:options.links.eq(tab)};}
if(children.filter(tab).length){return{tab:children.filter(tab),link:options.links.filter(function(){return filterTab.apply(this,[tab]);})};}
return{tab:children.filter('#'+tab),link:options.links.filter(function(){return filterTab.apply(this,['#'+tab]);})};}
function getCurrent(){return options.links.parent().filter('.'+options.currentClass).index();}
function next(loop){++current;if(loop===undefined)loop=options.loop;if(current<children.length){return switchTab(current,true);}else if(loop&&current>=children.length){return switchTab(0,true);}
return false;}
function prev(loop){--current;if(loop===undefined)loop=options.loop;if(current>=0){return switchTab(current,true);}else if(loop&&current<0){return switchTab(children.length-1,true);}
return false;}
function onSwitch(tab){if(options.history&&options.historyOnInit&&firstTime&&history!==undefined&&('pushState'in history)){firstTime=false;window.setTimeout(function(){history.replaceState(null,'',tab);},100);}
current=getCurrent();if(options.onSwitch&&typeof options.onSwitch==='function'){options.onSwitch(tab,api());}
tabcontent.trigger('tabcontent.switch',[tab,api()]);}
function switchTab(tab,api){if(!tab.toString().match(/^#/)){tab='#'+getTab(tab).tab.attr('id');}
if(!tabExists(tab)){return false;}
options.links.attr('aria-selected','false').parent().removeClass(options.currentClass);options.links.filter(function(){return filterTab.apply(this,[tab]);}).attr('aria-selected','true').parent().addClass(options.currentClass);children.hide();if(options.history&&api){if(history!==undefined&&('pushState'in history)){history.pushState(null,'',tab);}else{window.location.hash=tab;}}
children.attr('aria-hidden','true').filter(tab).show(options.speed,function(){if(options.speed){onSwitch(tab);}}).attr('aria-hidden','false');if(!options.speed){onSwitch(tab);}
return true;}
function apiSwitch(tab){return switchTab(tab,true);}
function hashSwitch(e){switchTab(loc.hash);}
function init(){if(tabExists(loc.hash)){switchTab(loc.hash);}
else if(options.links.parent().filter('.'+options.currentClass).length){switchTab(options.links.parent().filter('.'+options.currentClass).index());}
else if(options.errorSelector&&children.find(options.errorSelector).length){children.each(function(){if($(this).find(options.errorSelector).length){switchTab("#"+$(this).attr("id"));return false;}});}
else{switchTab("#"+children.filter(":first-child").attr("id"));}
if(options.errorSelector){children.find(options.errorSelector).each(function(){var tab=getTab($(this).parent());tab.link.parent().addClass(options.tabErrorClass);});}
if('onhashchange'in window){$(window).bind('hashchange',hashSwitch);}else{var current_href=loc.href;window.setInterval(function(){if(current_href!==loc.href){hashSwitch.call(window.event);current_href=loc.href;}},100);}
$(options.links).on('click',function(e){switchTab($(this).attr('href').replace(/^[^#]+/,''),options.history);e.preventDefault();});if(options.onInit&&typeof options.onInit==='function'){options.onInit(api());}
tabcontent.trigger('tabcontent.init',[api()]);}
function api(){return{'switch':apiSwitch,'switchTab':apiSwitch,'getCurrent':getCurrent,'getTab':getTab,'next':next,'prev':prev,'isFirst':isFirst,'isLast':isLast};}
init();return api();};$.fn.tabbedContent=function(options){return this.each(function(){var tabs=new Tabbedcontent($(this),options);$(this).data('api',tabs);});};})(window.jQuery||window.Zepto||window.$,document,window);
)=====";

const uint8_t JS_TABBEDCONTENT_GZIP[1412] PROGMEM = { 31,139,8,0,174,85,124,92,2,255,173,88,221,111,219,54,16,127,239,95,225,56,158,73,193,178,146,188,90,85,7,44,235,128,2,3,134,45,125,90,145,14,140,68,219,90,21,74,19,169,124,192,245,255,190,59,138,164,72,197,113,179,172,47,182,73,30,239,251,126,119,116,74,215,157,200,85,89,11,58,139,139,58,239,110,185,80,241,125,41,138,250,62,238,68,193,215,165,224,69,180,155,118,146,79,164,106,203,92,77,211,59,214,78,62,178,155,27,94,228,181,80,112,33,115,76,20,187,49,123,113,221,224,142,140,118,72,14,140,88,87,41,153,237,170,82,124,145,171,129,46,105,90,126,71,163,4,4,21,148,48,18,37,21,23,27,181,253,241,8,201,138,36,112,42,39,140,196,188,109,235,246,138,87,60,87,117,11,251,122,189,188,229,82,178,13,39,177,108,56,47,86,107,86,73,30,215,226,234,190,84,249,214,45,63,136,82,153,69,222,181,45,72,186,172,152,148,43,194,192,152,59,184,13,66,222,35,63,179,189,101,114,169,249,75,18,111,75,9,2,31,87,170,237,184,93,252,214,115,212,91,85,93,55,61,239,125,188,46,91,169,62,150,183,60,51,194,182,101,85,128,184,204,51,209,238,209,200,114,203,250,40,36,102,9,28,243,204,70,40,129,5,67,247,90,197,51,209,85,85,106,92,158,205,18,254,0,92,11,106,221,238,130,145,150,107,122,66,205,42,209,177,152,148,66,42,38,114,94,175,39,179,40,218,5,135,217,44,36,142,210,253,27,27,236,9,186,231,1,180,147,24,246,104,215,114,213,181,98,242,83,93,87,156,9,106,45,130,176,85,138,183,154,198,196,54,224,82,202,95,208,63,212,49,176,38,101,217,121,72,247,65,40,42,186,91,71,8,191,127,184,120,74,246,43,59,204,205,41,212,43,177,188,240,175,245,74,66,86,7,182,204,168,2,247,71,9,83,170,165,100,219,242,53,228,231,45,131,36,162,130,223,79,254,224,155,247,15,13,222,88,144,25,137,2,179,54,92,57,110,224,116,248,14,29,109,68,236,224,0,171,33,70,247,174,2,95,39,252,31,188,150,64,26,240,7,26,69,123,96,15,156,122,63,32,223,128,135,179,174,191,21,61,207,208,50,58,22,160,131,156,61,186,67,220,205,177,195,2,231,69,231,219,132,53,77,245,168,125,26,127,2,54,215,224,49,173,205,17,105,228,148,44,190,147,68,195,202,73,245,99,117,217,167,201,192,34,148,212,176,254,212,105,149,144,133,165,240,177,35,178,209,242,217,11,168,70,138,128,16,237,22,11,67,141,133,136,91,144,151,3,204,234,13,39,24,22,72,101,46,188,29,165,175,83,84,106,80,195,92,51,148,49,2,16,40,192,1,107,38,70,204,124,110,14,223,101,223,230,115,110,57,188,177,238,68,216,242,45,210,128,220,91,180,92,190,214,162,119,217,249,43,141,120,123,240,226,184,188,191,105,133,109,8,174,72,173,162,6,114,231,243,209,70,15,240,243,185,3,244,249,220,156,156,120,70,207,231,148,52,157,220,94,41,166,56,41,197,196,208,64,189,142,58,65,106,32,94,114,189,89,119,202,207,101,115,45,105,121,83,177,156,107,118,20,113,62,38,186,53,129,105,241,197,249,57,90,104,65,206,79,228,212,51,200,90,58,159,171,199,6,241,103,124,0,65,35,86,52,25,122,128,239,161,152,53,37,213,24,231,181,45,152,8,54,27,172,7,111,175,15,9,209,21,222,95,186,14,202,97,8,153,33,208,190,63,65,168,83,245,21,112,20,27,106,81,246,236,243,233,25,248,13,206,50,172,94,15,84,113,2,48,184,92,22,36,234,33,237,36,108,73,3,30,152,208,135,69,221,223,102,109,201,150,82,79,16,188,32,49,209,180,0,243,174,228,91,126,91,223,113,93,222,244,96,205,167,223,5,7,159,81,7,147,216,215,134,21,197,49,85,92,21,108,203,130,135,73,224,178,218,186,252,191,229,174,77,71,119,60,202,69,172,212,157,73,104,59,158,36,48,50,109,113,204,73,247,144,164,86,53,207,80,208,178,224,98,48,211,111,69,114,91,223,59,229,245,32,23,123,62,245,12,211,103,144,180,126,57,131,192,232,160,32,19,94,61,8,29,103,96,113,3,85,243,243,23,220,231,227,198,19,32,194,172,182,208,227,46,161,35,204,45,30,237,6,98,240,148,118,82,56,18,1,202,80,59,54,152,124,118,132,207,221,182,72,249,218,198,101,219,193,192,253,127,182,192,67,74,5,227,58,224,249,208,236,97,90,61,72,52,40,54,76,56,12,188,24,166,130,29,212,94,194,103,48,112,122,58,93,4,35,222,180,44,166,160,119,136,26,123,107,200,232,230,120,82,153,174,52,188,47,245,254,52,228,168,209,233,176,94,187,23,57,97,108,51,62,170,16,21,13,34,90,43,108,144,162,20,225,17,3,119,4,57,130,231,13,66,80,175,38,169,5,230,84,190,101,98,163,49,160,47,234,104,55,163,230,87,114,163,95,98,30,85,60,228,183,133,2,212,208,228,197,95,56,57,103,58,89,225,135,215,245,96,146,229,237,29,171,70,209,244,175,1,58,217,139,128,65,78,74,146,179,170,50,250,36,252,14,168,1,251,14,74,219,187,46,57,126,203,64,123,163,36,175,202,252,11,25,144,37,168,206,131,243,191,233,199,208,155,62,125,62,189,94,156,1,4,70,241,8,100,163,148,235,87,43,168,243,115,255,6,163,218,193,65,79,238,135,137,39,29,25,183,159,237,199,120,72,95,218,137,17,71,160,15,31,232,193,122,203,14,249,196,116,236,149,67,182,152,56,31,4,187,195,124,65,86,195,111,189,175,73,251,239,152,224,196,75,86,248,25,19,116,3,89,225,103,76,204,91,143,172,204,15,220,193,231,26,110,224,183,126,153,104,240,179,53,168,21,77,247,233,44,89,11,76,216,27,94,92,142,255,116,112,255,52,88,192,134,32,60,87,48,50,195,135,91,240,239,133,141,242,240,72,182,97,47,152,98,208,63,154,82,247,56,83,34,240,97,243,238,239,223,59,222,62,126,253,106,150,127,242,70,213,110,245,228,255,148,40,253,23,8,208,63,203,110,17,0,0 };
