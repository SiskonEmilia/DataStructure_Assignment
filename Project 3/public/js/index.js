$(function () {
  $.contextMenu ({
    selector: 'span',
    callback: function (key, options) {
      var m = "clicked: " + key;
      window.console && console.log(m) || alert(m);
    },
    items: {
      "Add...": { name: "Add...", icon: "fa-plus",
        items: {
          "Add to parent": { name: "Parent", icon: "fa-user-plus"},
          "Add to brother": { name: "Brother", icon: "fa-user-plus"},
          "Add to couple": { name: "Couple", icon: "fa-user-plus"},
          "Add to children": { name: "Child", icon: "fa-user-plus"}
        }
      },
      "detail": { name: "Detail", icon: "fa-info-circle"},
      "edit": { name: "Edit", icon: "fa-pencil-square"},
      "delete": { name: "Delete", icon: "delete" },
      "sep1": "---------",
      "quit": {
        name: "Quit", icon: function () {
          return 'context-menu-icon context-menu-icon-quit';
        }
      },
      
    },
    trigger: "left"
  });

  $.contextMenu ({
    selector: 'span',
    callback: function (key, options) {
      var m = "clicked: " + key;
      window.console && console.log(m) || alert(m);
    },
    items: {
      "Add...": { name: "Add...", icon: "fa-plus",
        items: {
          "Add to parent": { name: "Parent", icon: "fa-user-plus"},
          "Add to brother": { name: "Brother", icon: "fa-user-plus"},
          "Add to couple": { name: "Couple", icon: "fa-user-plus"},
          "Add to children": { name: "Child", icon: "fa-user-plus"}
        }
      },
      "detail": { name: "Detail", icon: "fa-info-circle"},
      "edit": { name: "Edit", icon: "fa-pencil-square"},
      "delete": { name: "Delete", icon: "delete" },
      "sep1": "---------",
      "quit": {
        name: "Quit", icon: function () {
          return 'context-menu-icon context-menu-icon-quit';
        }
      },
      
    },
    trigger: "right"
  });


});