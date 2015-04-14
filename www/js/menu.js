$('body').ready(function(){
	$(this).scroll(function(){
		if ($(this).scrollTop()>170)
		{
			$('.main>.menu').addClass('disclosed')
		}else {
			$('.main>.menu').removeClass('disclosed')
		}
	})
})