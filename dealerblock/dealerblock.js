(function ($) {
    
  Drupal.behaviors.dealerblock = {
    attach: function (context, settings) {
      
     var country = $('#edit-country').val();
     if(country=='us')
     {
         $('#zip').show();
         $('#distance').show();
         $('#dealers-zip').show();
         $('#dealermapfilterblock-form .gap').show();
     }
     else
     {
          $('#zip').hide();
          $('#distance').hide();
          $('#edit-zip').val('');
      
          $('#dealers-zip').hide();
          $('#dealermapfilterblock-form .gap').hide();
     }
     
    }   
  };
  
  
})(jQuery);

