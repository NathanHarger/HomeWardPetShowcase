import QtQuick 2.0





GridView{
    model: animalModel
    width: 1000; height:1000;
    id:mainView
   cellWidth:300; cellHeight:300
    delegate:
         Loader{
            id: mainLoader

            source: "shelterview.qml"
         }
}



