import QtQuick 2.0

GridView {
    id :grid
    anchors.fill:parent
    cellWidth: 80; cellHeight: 80;
    model: AnimalListModel{}
    delegate: contactDelegate
    focus: true
}
