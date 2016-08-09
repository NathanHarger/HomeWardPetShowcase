import QtQuick 2.0





GridView{
    model: animalModel
    width: 750; height:1334
    id:mainView
    cellWidth:width/4; cellHeight:height/4
    delegate:
        Loader{
            id: mainLoader

            source: "shelterview.qml"
         }
}



