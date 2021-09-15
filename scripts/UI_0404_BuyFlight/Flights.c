Flights()
{
	lr_start_transaction("0404_BuyFlight");
	lr_start_transaction("WebTourConnection");
	
	web_reg_find("Text/IC=Web Tours",
		LAST);

	web_reg_save_param("userSession",
		"LB=name=\"userSession\" value=\"",
		"RB=\"",
		LAST);


	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");
	lr_end_transaction("WebTourConnection",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("Login");
	web_reg_find("Text/IC=User password was correct",
		LAST);
	web_reg_find("Text/IC={Username}", LAST);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={Username}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=82", ENDITEM, 
		"Name=login.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("Flights");
	web_reg_find("Text/IC= User has returned to the search page.",
		LAST);

	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Flights",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("SearchFlight");
	web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB/IC=\"",
		LAST);
	web_reg_find("Text/IC=Flight Selection", LAST); 
	web_reg_find("Text/IC={SeatType}", LAST);
	web_reg_find("Text/IC={Seatpref}", LAST);
	web_reg_find("Text/IC=<B>{Department}</B> to <B>{Arrival}</B>", LAST);
	web_reg_find("Text/IC=<B>{Departdate}",LAST);

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={Department}", ENDITEM, 
		"Name=departDate", "Value={Departdate}", ENDITEM, 
		"Name=arrive", "Value={Arrival}", ENDITEM, 
		"Name=returnDate", "Value={Returndate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={Seatpref}", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=55", ENDITEM, 
		"Name=findFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("SearchFlight",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("ChooseFlight");
	web_reg_find("Text/IC={SeatType}", LAST);
	web_reg_find("Text/IC={Seatpref}", LAST);
	web_reg_find("Text/IC=Flight Reservation", LAST); 
	
	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=seatPref", "Value={Seatpref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=69", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("ChooseFlight",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("PaymentData"); 
	web_reg_find("Text/IC=Thank you for booking through Web Tours", LAST);
	web_reg_find("Text/IC={FirstName}", LAST);
	web_reg_find("Text/IC={LastName}", LAST);
	web_reg_find("Text/IC={SeatType}", LAST);
	

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=pass1", "Value={FullName}", ENDITEM, 
		"Name=creditCard", "Value={CreditCard}", ENDITEM, 
		"Name=expDate", "Value={ExpDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=seatPref", "Value={Seatpref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=60", ENDITEM, 
		"Name=buyFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("PaymentData",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("Itinerary");

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("SignOff");

	web_reg_find("Text/IC=<title>Web Tours</title>",
		LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);
	lr_end_transaction("0404_BuyFlight", LR_AUTO);

	return 0;
}