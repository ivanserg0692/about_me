$().ready(function(){
	$('.carousel').jcarousel({scroll: 1,
    visible: 1,
    animation: 3000,
    auto: 8,
    wrap: 'circular',
    itemFallbackDimension: 300})
})