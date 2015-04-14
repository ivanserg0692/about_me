$().ready(function(){
	$('.topic [rel="#overlay_img"][src]').overlay({mask: '#000', effect: 'apple',onBeforeLoad:onBeforeLoadOverlayImg})
})
function onBeforeLoadOverlayImg()
{
	$('#overlay_img img').attr('src',this.getTrigger().attr('src'))
}