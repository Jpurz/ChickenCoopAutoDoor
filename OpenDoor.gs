var sheet_id = "xxXXXXXXXXXXXXXXXXXXXXXXXxx";
var sheet_name = "XXXXXXXXXX";
function OpenDoor() {
  var ss = SpreadsheetApp.openById(sheet_id);
  var sheet = ss.getSheetByName(sheet_name);
  sheet.getRange('A2').activate();
  sheet.getCurrentCell().setValue('Open');
  };
