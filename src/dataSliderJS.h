const char JS_SLIDER[] PROGMEM = R"=====(
function rkmd_rangeSlider(selector){var self,slider_width,slider_offset,curnt,sliderDiscrete,range,slider;self=$(selector);slider_width=self.width();slider_offset=self.offset().left;sliderDiscrete=self;sliderDiscrete.each(function(i,v){curnt=$(this);curnt.append(sliderDiscrete_tmplt());range=curnt.find('input[type="range"]');slider=curnt.find('.slider');slider_fill=slider.find('.slider-fill');slider_handle=slider.find('.slider-handle');slider_label=slider.find('.slider-label');var range_val=parseInt(range.val());slider_fill.css('width',range_val+'%');slider_handle.css('left',range_val+'%');slider_label.find('span').text(range_val);});self.on('mousedown touchstart','.slider-handle',function(e){if(e.button===2){return false;}
var parents=$(this).parents('.rkmd-slider');var slider_width=parents.width();var slider_offset=parents.offset().left;var check_range=parents.find('input[type="range"]').is(':disabled');if(check_range===true){return false;}
$(this).addClass('is-active');var moveFu=function(e){var pageX=e.pageX||e.changedTouches[0].pageX;var slider_new_width=pageX-slider_offset;if(slider_new_width<=slider_width&&!(slider_new_width<'0')){slider_move(parents,slider_new_width,slider_width,true);}};var upFu=function(e){$(this).off(handlers);parents.find('.is-active').removeClass('is-active');};var handlers={mousemove:moveFu,touchmove:moveFu,mouseup:upFu,touchend:upFu};$(document).on(handlers);});self.on('mousedown touchstart','.slider',function(e){if(e.button===2){return false;}
var parents=$(this).parents('.rkmd-slider');var slider_width=parents.width();var slider_offset=parents.offset().left;var check_range=parents.find('input[type="range"]').is(':disabled');if(check_range===true){return false;}
var slider_new_width=e.pageX-slider_offset;if(slider_new_width<=slider_width&&!(slider_new_width<'0')){slider_move(parents,slider_new_width,slider_width,true);}
var upFu=function(e){$(this).off(handlers);};var handlers={mouseup:upFu,touchend:upFu};$(document).on(handlers);});};function sliderDiscrete_tmplt(){var tmplt='<div class="slider">'+
'<div class="slider-fill"></div>'+
'<div class="slider-handle"><div class="slider-label"><span>0</span></div></div>'+
'</div>';return tmplt;}
function slider_move(parents,newW,sliderW,send){var slider_new_val=parseInt(Math.round(newW/sliderW*100));var slider_fill=parents.find('.slider-fill');var slider_handle=parents.find('.slider-handle');var range=parents.find('input[type="range"]');slider_fill.css('width',slider_new_val+'%');slider_handle.css({'left':slider_new_val+'%','transition':'none','-webkit-transition':'none','-moz-transition':'none'});range.val(slider_new_val);if(parents.find('.slider-handle span').text()!=slider_new_val){parents.find('.slider-handle span').text(slider_new_val);var number=parents.attr('id').substring(2);if(send)websock.send('slvalue:'+slider_new_val+':'+number);}}
)=====";

const uint8_t JS_SLIDER_GZIP[865] PROGMEM = { 31,139,8,0,174,85,124,92,2,255,237,86,207,111,155,48,20,190,247,175,72,163,174,134,149,184,89,143,33,238,101,211,164,29,118,218,164,77,170,170,200,1,83,172,16,131,176,73,182,209,252,239,123,254,1,1,66,170,110,167,29,118,194,246,251,252,252,222,247,62,243,156,84,34,82,60,23,147,114,179,141,87,37,21,79,236,75,198,99,86,122,146,101,44,82,121,233,215,59,90,78,96,150,4,210,88,86,123,30,171,180,153,228,73,34,153,10,162,170,20,202,173,125,224,50,42,153,98,129,113,231,22,67,237,129,92,29,221,134,93,111,68,91,177,25,122,173,197,186,182,38,59,246,124,156,177,68,133,253,115,12,98,176,134,25,141,82,47,113,217,121,60,216,249,181,137,17,66,80,41,151,126,104,102,152,22,5,19,177,215,223,188,82,219,34,131,195,252,208,100,64,44,52,225,0,68,92,20,149,122,80,63,11,70,166,198,58,125,68,77,196,61,32,182,107,173,113,149,240,44,35,118,220,135,204,180,229,136,75,169,136,51,54,142,180,182,35,54,163,107,118,198,169,49,1,82,87,207,4,186,218,209,140,20,180,148,236,147,80,158,89,194,176,164,211,236,68,136,35,41,61,100,42,129,130,118,223,13,122,51,12,208,2,117,57,206,225,76,4,46,42,89,80,129,124,172,216,15,119,180,70,251,225,193,15,109,121,133,135,182,121,37,89,156,239,197,68,229,85,148,74,69,75,112,61,76,61,104,107,202,252,154,39,30,195,235,74,169,92,16,66,238,252,26,170,7,37,152,36,52,147,44,60,92,232,220,33,99,38,148,108,234,142,221,28,136,210,146,159,181,85,50,42,239,74,210,1,91,85,118,0,78,153,13,162,47,78,141,139,82,22,109,236,117,106,81,47,232,7,115,136,103,17,115,73,215,25,139,33,24,72,172,235,130,16,85,86,236,36,189,38,37,26,199,239,51,170,203,193,229,140,2,59,59,230,18,218,230,59,246,177,34,93,206,44,39,79,236,59,97,216,124,159,159,161,150,169,62,39,254,170,137,103,242,97,254,104,77,221,156,5,219,183,196,128,105,214,163,66,7,60,196,45,73,151,206,235,235,203,83,4,154,35,223,175,221,178,142,213,115,100,5,67,104,255,223,99,216,8,15,7,19,95,85,12,50,108,104,129,208,60,171,154,18,238,123,191,12,184,195,20,46,153,62,123,132,66,123,64,227,131,212,70,162,26,187,176,196,6,70,169,221,5,131,168,138,133,14,202,90,225,247,98,102,135,240,202,139,243,168,218,66,20,190,22,252,49,180,215,223,130,255,242,31,164,119,34,78,39,234,127,65,158,23,127,160,206,81,165,253,133,142,14,97,115,214,100,188,167,153,251,111,198,4,45,99,190,155,68,90,246,100,106,209,211,123,116,115,49,178,110,90,212,244,126,121,11,150,115,16,27,7,128,78,77,166,19,128,69,119,129,251,249,242,214,124,173,179,142,75,59,10,93,149,77,140,64,226,32,159,126,29,160,0,223,28,247,240,5,138,220,107,229,88,158,94,211,251,76,85,138,203,188,2,37,234,157,183,110,231,219,119,243,185,223,83,184,233,213,131,63,70,191,89,119,192,174,97,143,195,219,142,221,246,225,215,220,136,179,29,185,159,217,185,182,92,219,190,188,56,69,7,72,193,33,146,107,70,209,2,137,92,64,75,69,179,61,91,111,184,154,141,218,182,249,175,17,195,193,61,142,204,19,162,127,142,185,191,47,177,49,233,190,6,252,75,50,216,94,191,122,239,240,92,205,177,168,182,107,120,138,53,62,168,82,37,144,12,127,21,44,171,181,84,37,23,79,222,157,9,209,232,5,50,151,121,180,193,122,2,207,148,12,252,84,108,129,110,134,212,193,146,245,172,251,206,111,101,146,232,206,54,11,0,0 };
