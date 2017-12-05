$(function () {
  const OL_Action_Root = "http://localhost:8888";

  $.contextMenu ({
    selector: 'span',
    callback: function (key, options) {
      switch(key) {
        case 'addParent':
          getInfo();
          Req_ajax();
        break;
        
        case 'addBrother':
          getInfo();
        break;
        
        case 'addCouple':
          getInfo();
        break;
        
        case 'addChild':
          getInfo();
        break;
        
        case 'edit':
          getInfo();
        break;
        
        case 'delete':
        
        break;
        
        case 'detail':
        
        break;
        
        case 'quit':
          window.close();
        break;
        
        default:
        break;
      }
    },
    items: {
      "Add...": { name: "Add...", icon: "fa-plus",
        items: {
          "addParent": { name: "Parent", icon: "fa-user-plus"},
          "addBrother": { name: "Brother", icon: "fa-user-plus"},
          "addCouple": { name: "Couple", icon: "fa-user-plus"},
          "addChild": { name: "Child", icon: "fa-user-plus"}
        }
      },
      "detail": { name: "Detail", icon: "fa-info-circle"},
      "edit": { name: "Edit", icon: "fa-pencil-square"},
      "delete": { name: "Delete", icon: "delete" },
      "sep1": "---------",
      "quit": {
        name: "Quit", icon: 'context-menu-icon context-menu-icon-quit'
      },
      
    }
  });

  /* if success, send an array to the callback, which contains all the data needed */
  function getInfo(callback) {
    
  }

  function sendEdit(data) {
    
  }

  function warning(msg) {

  }

  function Req_ajax(dataIn, jump) {
    $.ajax({
      data: dataIn,
      url: OL_Action_Root + "/func",
      dataType: 'json',
      cache: false,
      timeout: 5000,
      type: "post",
      success: function (data) {
        /*if (data.isError)
          warning(data.data);
        else if (jump === undefined)
          $('.tree').innerHTML = data.data;
        else
          window.location.href = data.data;*/
        if (data.isError)
          console.log('wtf?');
        else
          console.log(data.data);
        console.log('!');
      },
      error: function (jqXHR, textStatus, errorThrown) {
        console.log(jqXHR);
      }
    });
  }

});