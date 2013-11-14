$(document).ready(function(){
  $("#second").hide()
  $("#third").hide()
 
 
  $("#buttonone").click(function(){
  $("#second").hide()
  $("#third").hide()
  $("#first").show()
  $("#first").fadeTo(0, 0)
  $("#first").fadeTo("slow", 1)
  })
 
  $("#buttontwo").click(function(){
  $("#first").hide()
  $("#third").hide()
  $("#second").show()
  $("#second").fadeTo(0, 0)
  $("#second").fadeTo("slow", 1)
  })
 
  $("#buttonthree").click(function(){
  $("#first").hide()
  $("#second").hide()
  $("#third").show()
  $("#third").fadeTo(0, 0)
  $("#third").fadeTo("slow", 1)
  })
  
})