Action()
{

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

	lr_think_time(26);

	lr_start_transaction("3_signup");

	web_url("sign up now", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(71);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=AlexS", ENDITEM, 
		"Name=password", "Value=vjkjrj", ENDITEM, 
		"Name=passwordConfirm", "Value=vjkjrj", ENDITEM, 
		"Name=firstName", "Value=Alexander", ENDITEM, 
		"Name=lastName", "Value=Smirnov", ENDITEM, 
		"Name=address1", "Value=Alley", ENDITEM, 
		"Name=address2", "Value=Moscow", ENDITEM, 
		"Name=register.x", "Value=18", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

	lr_think_time(5);

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_signup",LR_AUTO);

	return 0;
}