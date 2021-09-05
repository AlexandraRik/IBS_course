Login()
{
	

	
	lr_start_transaction("01_GeneralTransaction");
	


  	lr_start_transaction("WebTourConnection"); 



	
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
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_end_transaction("WebTourConnection", LR_AUTO);
	
	lr_think_time(5);
	
	
	lr_start_transaction("Login");
	
   

	//web_reg_find("Text/IC=User password was correct",LAST);

	web_reg_find("Text/IC=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Username}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=55", ENDITEM,
		"Name=login.y", "Value=3", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	
	
	lr_end_transaction("01_GeneralTransaction", LR_AUTO);


	return 0;
}