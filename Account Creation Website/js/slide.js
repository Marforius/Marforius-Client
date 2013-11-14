		$(document).ready(function(){
          $("#second").hide()
          $("#third").hide()
         
          $("#buttonone").click(function(){
          $("#second").hide("slow")
          $("#third").hide("slow")
          $("#first").show()
          })
         
          $("#buttontwo").click(function(){
          $("#first").hide("slow")
          $("#third").hide("slow")
          $("#second").show()
          })
               
         $("#buttonthree").click(function(){
          $("#first").hide("slow")
          $("#second").hide("slow")
          $("#third").show()
          })
        })