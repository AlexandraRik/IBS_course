Action()
{

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_think_time(9);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=Dean", ENDITEM, 
		"Name=password", "Value=neaD", ENDITEM, 
		"Name=login.x", "Value=65", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(8);

	web_submit_form("itinerary.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=45", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		LAST);

	return 0;
}