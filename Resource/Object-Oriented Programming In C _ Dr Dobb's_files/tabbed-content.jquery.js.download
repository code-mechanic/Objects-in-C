$(function() {
    
if( $(".tabs").is("*") )
{
    
    $('.tabs').wrapInner('<div class="tabbed" />');
    
    $('.tabbed').each(function(i) {
        $(this).attr('id','t'+i)
        var t = '#t' + i;
        $(t + ' .tab-content').hide(); // Hide all tab content
        $(t + ' .tab-content').eq(0).show(); // Show first tab content
        $(t + ' .tab-content .tab').hide(); // Hide headers inside tab content
        $(t + ' ul.toc li').eq(0).addClass('current'); // Set current class to first tab
        
        $(t + ' ul.toc li').click( function() {   
            $(t + ' ul.toc li').removeClass('current');
            $(this).addClass('current');
            $(t + ' .tab-content').hide();
            var j = $(t + ' ul.toc li').index($(this));
            $(t + ' .tab-content').eq(j).show();
            return false;
        });
    });

}

});