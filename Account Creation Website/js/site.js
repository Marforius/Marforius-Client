function getOnline(id) {
$("#serverstats2").slideUp("medium");
$.ajax({
    url: 'js/online.php',
    dataType: 'json',
    async: true,
    cache: false,
    success: function (data) {
  $("#serverstats2").html(data.online);
  setTimeout(function() { $("#serverstats2").slideDown("slow"); }, 500);
    }
})
}