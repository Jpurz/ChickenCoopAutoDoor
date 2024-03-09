var sheet_id = "XXXXXXXXXXXXXXXXXXXXXXXXXXX";
var sheet_name = "XXXXXXXXXX";
function CloseDoor() {
  var ss = SpreadsheetApp.openById(sheet_id);
  var sheet = ss.getSheetByName(sheet_name);
  sheet.getRange('A3').activate();
  sheet.getCurrentCell().setValue('Close');
  };
