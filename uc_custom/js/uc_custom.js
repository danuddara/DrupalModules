/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {
    
    $( document ).ready(function() {
          // Handler for .ready() called.
   
        var clock = new FlipClock($('.your-clock'), {
           /* callbacks:{
                        stop: function() {
                                        console.log("triggered");
		        		$('.time').html('The clock has stopped!');
		        	}
                
                      }*/
          
            
            });

        var timestamp = $('#timestamp').val();
        
        clock.setTime(parseInt(timestamp));
        clock.setCountdown(true);
        console.log(timestamp);
        if(timestamp<30)
            {
                $('.add_to_basket').fadeOut(timestamp*1000+5000); // fade out and change the button to buy time now.
            }
          else if(timestamp==null) //solved cached problem in the form. after exceeding the limit.
              {
                  $('.add_to_basket').val('Buy time to get this');
                  $('.add_to_basket').addClass('buy_time').removeClass('add_to_basket');
              }
        
        var img = $('#block-uc-custom-file-transfer-block .content').html();
        $('.form-actions').append(img);
        //console.log(img);
        //show the file transfer icon.
        
        $('.add_to_basket').click(function(e){
            e.preventDefault();
            $(this).parent().find('.file_transfer').show();
            $(this).closest('form').submit();
            return true;
            
            
        });
        
        
        
    
     });

}(jQuery));

