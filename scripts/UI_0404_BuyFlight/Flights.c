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
		"URL=http://127.0.0.1:1080/WebTours/", 
		"TargetFrame=", 
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
	web_reg_find("Text/IC={Username}", LAST);
	
	

	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Username}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=51", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		LAST);

	

		
		lr_end_transaction("Login", LR_AUTO);
		


	lr_start_transaction("Flights");

	web_reg_find("Text/IC= User has returned to the search page.",
		LAST);

	web_url("Search Flights Button",
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_think_time(29);
	lr_end_transaction("Flights", LR_AUTO); 

	
	lr_start_transaction("SearchFlight");

	

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
		"Snapshot=t4.inf",
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
		"Name=findFlights.x", "Value=59", ENDITEM,
		"Name=findFlights.y", "Value=12", ENDITEM,
		LAST);

	lr_think_time(5);
	lr_end_transaction("SearchFlight", LR_AUTO);

	lr_start_transaction("ChooseFlight");




//		web_reg_save_param("outboundFlight",
//		"LB/IC=outboundFlight\" value=\"",
//		"RB/IC=\"",
//		"Ord=ALL",LAST); 
	web_reg_save_param("outboundFlight",
		"LB/IC=\"outboundFlight\" value=\"",
		"RB/IC=\"",
		LAST);

	

	web_reg_find("Text/IC={SeatType}", LAST);
	web_reg_find("Text/IC={Seatpref}", LAST);
		
	web_reg_find("Text/IC=Flight Reservation", LAST); 
	
	web_submit_data("reservations.pl_2",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={SeatType}", ENDITEM, 
		"Name=seatPref", "Value={Seatpref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=79", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(5);
	
	lr_end_transaction("ChooseFlight", LR_AUTO);
	
	lr_start_transaction("PaymentData");

	web_reg_find("Text/IC=Thank you for booking through Web Tours",
		LAST);
	web_reg_find("Text/IC={FirstName}", LAST);
	web_reg_find("Text/IC={LastName}", LAST);
	web_reg_find("Text/IC={SeatType}", LAST);
	
 
	
	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
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
		"Name=outboundFlight", "Value={userSession}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=23", ENDITEM, 
		"Name=buyFlights.y", "Value=5", ENDITEM, 
		LAST);
	lr_end_transaction("PaymentData", LR_AUTO);
	lr_end_transaction("0404_BuyFlight", LR_AUTO);
	
	


	return 0;
}