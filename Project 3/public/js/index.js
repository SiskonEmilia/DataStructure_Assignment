$(function () {
  const OL_Action_Root = "http://localhost:8888";
  var options = {"closeOnOutsideClick": true};
  var tree = $('.tree');
  var dialogMsg = $('[data-remodal-id=modalMsg]').remodal(options);
  var dialogForm = $('[data-remodal-id=modalForm]').remodal(options);
  var Msg = $('#msg')[0]; 
  var genderLabel = $('.gender');

  var firstName = $('firstName');
  var lastName = $('lastName');
  var birthDay = $('birthDay');
  var deadDay = $('deadDay');

  genderLabel.click(function() {
    if (this.id == 'male')
      this.id = 'female';
    else
      this.id = 'male';
  });

  $.contextMenu ({
    selector: 'span',
    callback: function (key, options) {
      switch(key) {
        case 'addParent':
          var data = {
            "func": 0,
            "id": this[0].id
          };
          Req_ajax(data);
        break;
        
        case 'addBrother':
          var data = {
            "func": 2,
            "id": this[0].id
          };
          Req_ajax(data);
        break;
        
        case 'addCouple':
          var data = {
            "func": 1,
            "id": this[0].id
          };
          Req_ajax(data);
        break;
        
        case 'addChild':
          var data = {
            "func": 3,
            "id": this[0].id
          };
          Req_ajax(data);
        break;
        
        case 'edit':
          getInfo();
        break;
        
        case 'delete':
          var data = {
            "func": 4,
            "id": this[0].id
          };
          Req_ajax(data);
        break;
        
        case 'detail':
          var data = {
            "func": 5,
            "id": this[0].id
          };
          Req_ajax(data);
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
    Msg.textContent = msg;
    dialogMsg.open();
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
        if (data.isError) {
          warning(data.data);
        }
        else if (jump == undefined) {
          tree[0].innerHTML = data.data;
        }
        else {

        }
      },
      error: function (jqXHR, textStatus, errorThrown) {
        console.log(jqXHR);
      }
    });
  }

});