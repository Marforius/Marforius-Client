<?php
	
	// DATABASE CONNECTION
	$dbhost = 'localhost';
	$dbuser = 'root';
	$dbpass = 'example'; 
	$dbaccs = 'auth';
	$dbchars = 'characters';
	
	//XML STATS FILE (ONLY ARCEMU)
	$xmlfile = 'stats.xml'; 	// You need to provide a link to your XML file for server status to work correctly.
	$xmldisplay = 0; 			/* 1 = Displays Uptime & Online GMs
                                   2 = Displays only Uptime
                                   3 = Displays only Online GMs 
	                               0 = Disables showing Uptime/Online GMs */
	
	// WEBSITE SETTINGS
	$multi_ip = 1; 				// 1 = Allows multi IP registration, 0 = Disables multi IP registration.
	$js = 0;			    	// 0 = Fade effect, 1 = Slide effect.
	$theme = 2;             	/* Theme selector:
									0 = Nightvision (Default)
									1 = Tbc VS WotLK 
									2 = Cataclysm
								*/
	$max_players = 100;         // Configures how many players can play on the realm at the same time.
	$show_players = 50;         /* Configures how many players are shown on the status page, picks out randoms.
	 						 	   Having this count very high may slow down the loading time. */
	$show_all = true;           // true = Enables "Show All Link", false = Disables "Show All Link" (Of players online).
	
	// HOW TO CONNECT - EDIT HERE.
	$realmlist = 'marforius.servegame.com';
	$htc1t = 'Configuring your realmlist.';
	$htc1 = 'You need to configure your realmlist to be able to connect to our realm, you do so by navigating to your World of Warcraft directory folder which probably found under "C:\Program Files\World of Warcraft\" If you\'re using windows ("HD\Applications\World of Warcraft\" if you\'re using a Mac). Open it up, and if you\'re using windows7 or windows Vista you need to gain administrative permission to edit it (Run Notepad as admin, then file-open realmlist.wtf)<br /><br /> Edit the part where set "realmlist" is, from logon.worldofwarcraft.com to:<br />';
	
	$htc2t = 'Create your account!';
	$htc2 = 'If you have not already created your account on the index of this website, you can do so here: <a href="index.html">Click here</a>';
	
	$htc3t = 'Wait 1 minute';
	$htc3 = 'Our server requires that you wait 1 minute before attempting to log in. ';
	
	$htc4t = 'Go Play!';
	$htc4 = '';
?>