Action()
{
	lr_start_transaction("05_GeneralTransaction");

	lr_start_transaction("WebTourConnection"); 


	
	web_reg_save_param("userSession",
		"LB=name=\"userSession\" value=\"",
		"RB=\"",
		LAST);
	
	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");
	lr_end_transaction("WebTourConnection", LR_AUTO);
lr_think_time(5);
	
	lr_start_transaction("Login");
	

	web_reg_find("Text/IC=User password was correct",
		LAST);

	

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={Username}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=65", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST); 
	lr_end_transaction("Login", LR_AUTO);

	lr_start_transaction("Itinerary");

	web_reg_find("Text/IC=<input type=\"hidden\" ",
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(5);

	web_submit_form("itinerary.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		//"Name=2", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=45", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		LAST); 
	
	lr_end_transaction("Itinerary", LR_AUTO);
	lr_end_transaction("05_GeneralTransaction", LR_AUTO);



	return 0;
}