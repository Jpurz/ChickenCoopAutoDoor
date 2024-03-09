var SS = SpreadsheetApp.openById('XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX');
var sheet = SS.getSheetByName('sheetName');

function doGet(e){
  
  var read = e.parameter.read;  //include "   ?read=A2   " at the end of the url call.  
  
  if (read !== undefined){
    return ContentService.createTextOutput(sheet.getRange(read).getValue());
  }
  
  return ContentService.createTextOutput("No value passed as argument to script Url.");
}
