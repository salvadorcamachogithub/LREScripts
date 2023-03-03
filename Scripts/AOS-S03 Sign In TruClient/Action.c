//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Action()
{
	truclient_step("1", "Wait Math.floor(Math.random() * (26- 15) + 15) seconds", "snapshot=Action_1.inf");
	lr_start_transaction("AOS-S03-01 Access AOS URL");
	truclient_step("2", "Navigate to AOS_URL", "snapshot=Action_2.inf");
	lr_end_transaction("AOS-S03-01 Access AOS URL",0);
	truclient_step("3", "Wait Math.floor(Math.random() * (26- 15) + 15) seconds", "snapshot=Action_3.inf");
	lr_start_transaction("AOS-S03-02 Sign In");
	truclient_step("5", "Click on button (1) button", "snapshot=Action_5.inf");
	truclient_step("6", "Type loginUser in username textbox", "snapshot=Action_6.inf");
	truclient_step("7", "Type ************* in PasswordPassword passwordbox", "snapshot=Action_7.inf");
	truclient_step("8", "Press key Enter on PasswordPassword passwordbox", "snapshot=Action_8.inf");
	truclient_step("9", "Verify SPEAKERS Shop Now 's Visible Text contains SPEAKERS Shop Now", "snapshot=Action_9.inf");
	truclient_step("10", "Verify Mercury 's Visible Text contains Mercury", "snapshot=Action_10.inf");
	lr_end_transaction("AOS-S03-02 Sign In",0);
	truclient_step("11", "Wait Math.floor(Math.random() * (26- 15) + 15) seconds", "snapshot=Action_11.inf");
	lr_start_transaction("AOS-S03-03 Sign Out");
	truclient_step("12", "Click on MenuUserLink JavaScript link", "snapshot=Action_12.inf");
	truclient_step("13", "Click on MenuUserLink JavaScript link", "snapshot=Action_13.inf");
	lr_end_transaction("AOS-S03-03 Sign Out",0);

	return 0;
}
