$(window).load(function() {

function orienta (){
	//location.reload();
	
	if(window.orientation == 0 ||window.orientation == 180 ){  
	
	
	 /*$('meta[name=viewport]').attr('content', "width=1200, user-scalable=yes");*/
	/* 
	$('body').css({
     '-moz-transform':'scale(2,2)',
     '-webkit-transform':'scale(2,2)',
     '-o-transform':'scale(2,2)',
     '-ms-transform':'scale(2,2)',
     'transform':'scale(2,2)'
	
});
	$('#aviso').fadeIn('slow');*/
     } else {
	/* $('meta[name=viewport]').attr('description', "width=1200, user-scalable=yes");*/
	 
	/*$('body').css({
     '-moz-transform':'scale(1,1)',
     '-webkit-transform':'scale(1,1)',
     '-o-transform':'scale(1,1)',
     '-ms-transform':'scale(1,1)',
     'transform':'scale(1,1)'
});
	$('#aviso').fadeOut('slow');*/
    }
};
orienta();

var supportsOrientationChange = "onorientationchange" in window,
orientationEvent = supportsOrientationChange ? "orientationchange" : "resize";
window.addEventListener(orientationEvent, function(){orienta();}, false);

function pde(e){
  if(e.preventDefault){
        e.preventDefault();
		return false;
   } else {
        e.returnValue = false;
		return false;}
};

function pos(){
	if ($(window).width()>1100){
	window.posicao = ((($(window).width()-1100)*0.5)+40)+'px';
	} else {		
	window.posicao = '40px';
	}	
}

function alinha(){
	pos();
	$(".logo a").css('paddingLeft', posicao);
	if ($(window).width()>1100){
		$(".logo a").css('paddingLeft', posicao);
	}
}
	
$(document).ready(function(){
	$('#header').stop().delay(100).animate({opacity:1, top:'610px'}, 600, 'easeOutSine');
	$('#section').stop().delay(300).animate({opacity:1}, 500, 'easeOutSine');
	$('#footer').stop().delay(900).animate({opacity:1}, 500, 'easeOutSine');	
	$('#article').stop().delay(700).animate({opacity:1}, 500, 'easeOutSine');
	$('.logo').stop().delay(700).animate({opacity:1}, 500, 'easeOutSine');
	$('.icos').stop().delay(700).animate({opacity:1}, 500, 'easeOutSine');
	
	$('#home .h1esquerda').stop().delay(600).animate({opacity:1, marginTop:'350px'}, 800, 'easeOutSine');
	$('#home img').stop().delay(500).animate({opacity:1}, 1000, 'easeOutSine');
	$('#home .h1direita').stop().delay(600).animate({opacity:1, marginTop:'350px'}, 800, 'easeOutSine');
	
	$('#menu ul li a').hover(function() {
		$(this).find('span').stop().animate({opacity:1, top:'30px'}, 100, 'easeOutSine');
			}, function() {
		$(this).find('span').stop().animate({opacity:0, top:'0px'}, 200, 'easeOutSine');
	});
	alinha();
	orienta();	
});

$(window).resize(function(){	
		alinha();
		orienta();
});		
});