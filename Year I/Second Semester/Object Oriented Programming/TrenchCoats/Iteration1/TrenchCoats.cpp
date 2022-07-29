#include "TrenchCoats.h"
#include "trench_validator.h"
#include "utils.h"
#include "TrenchModel.h"
#include "qheaderview.h"
TrenchCoats::TrenchCoats(TrenchController cont, QWidget *parent)
    : QMainWindow(parent), cont(cont)
{
    ui.setupUi(this);
    ui.userButtonsStackedWidget->setCurrentIndex(0);
}

void TrenchCoats::handleDisplay()
{
    vector<TrenchCoat> trenches = this->cont.getAll();
    ui.coatsList->clear();
    for (auto t : trenches)
    {
        ui.coatsList->addItem(QString::fromStdString(t.toString()));
    }
}

void TrenchCoats::handleShowInternalBasket()
{
    vector<TrenchCoat> trenches = this->cont.getBasket();
    ui.shoppingBasketList->clear();
    for (auto t : trenches)
    {
        ui.shoppingBasketList->addItem(QString::fromStdString(t.toString()));
    }
}

void TrenchCoats::handleStartUser()
{
    ui.shoppingBasketList->clear();
    ui.userButtonsStackedWidget->setCurrentIndex(1);
    int size = ui.sizeUserBox->currentIndex();
    int data = ui.savingOptionBox->currentIndex() + 1;
    this->cont.setDataOption(data);
    vector<TrenchCoat> trenches = this->cont.getTrenchesBySize(size);
    for (auto t : trenches)
    {
        if (t.getPhotoLink() != "")
        {
            ui.shoppingBasketList->addItem(QString::fromStdString(t.toString()));
        }
    }
}

void TrenchCoats::handleAddTrench()
{   
    TrenchCoat t;
    int size, quantity;
    string colour, link;
    double price;
    size = ui.sizeComboBox->currentIndex();
    QString s = ui.colourLineEdit->text();
    if (s.isEmpty())
    {
        QMessageBox::information(this, "Error", "Colour field is empty", QMessageBox::Ok);
        return;
    }
    else
    {
        colour = s.toStdString();
    }
    s = ui.priceLineEdit->text();
    if (s.isEmpty())
    {
        QMessageBox::information(this, "Error", "Price field is empty", QMessageBox::Ok);
        return;
    }
    else
    {
        price = s.toDouble();
    }
    s = ui.quantityLineEdit->text();
    if (s.isEmpty())
    {
        QMessageBox::information(this, "Error", "Quantity field is empty", QMessageBox::Ok);
        return;
    }
    else
    {
        quantity = s.toInt();
    }
    s = ui.linkLineEdit->text();
    if (s.isEmpty())
    {
        QMessageBox::information(this, "Error", "Link field is empty", QMessageBox::Ok);
        return;
    }
    else
    {
        link = s.toStdString();
    }

    t = { size,colour,price,quantity,link };
    try
    {
        this->cont.addTrench(t);
        QMessageBox::information(this, "Added successfully", "Trench coat added successfully",QMessageBox::Ok);
        ui.colourLineEdit->clear();
        ui.priceLineEdit->clear();
        ui.quantityLineEdit->clear();
        ui.linkLineEdit->clear();
        this->handleDisplay();
    }
    catch (TrenchException& ex)
    {
        QMessageBox::information(this, "Error", ex.message().c_str(), QMessageBox::Ok);
    }
   
}

void TrenchCoats::handleDeleteTrench()
{
    QString s = ui.linkLineEdit->text();
    if (s.isEmpty())
    {
        QMessageBox::information(this, "Error", "Link field is empty", QMessageBox::Ok);
        return;
    }
    try
    {
        this->cont.deleteTrench(s.toStdString());
        QMessageBox::information(this, "Deleted successfully", "Trench was deleted successfully", QMessageBox::Ok);
        ui.linkLineEdit->clear();
        this->handleDisplay();
    }
    catch (TrenchException& ex)
    {
        QMessageBox::information(this, "Error", ex.message().c_str(), QMessageBox::Ok);
    }
}

void TrenchCoats::handleUpdateTrench()
{
    QString s = ui.linkLineEdit->text();
    if (s.isEmpty())
    {
        QMessageBox::information(this, "Error", "Link field is empty", QMessageBox::Ok);
        return;
    }

    string link = s.toStdString();
    string succesMessage = "Updated successfully ";
    string errorMessage = "Not updated ";
    int succes = 0, errors = 0;

    TrenchCoat currentTrench = this->cont.findTrenchByLink(link);
    int new_size = currentTrench.getSize();
    string new_colour = currentTrench.getColour();
    double new_price = currentTrench.getPrice();
    int new_quantity = currentTrench.getQuantity();


    new_size = ui.sizeComboBox->currentIndex();

    s = ui.colourLineEdit->text();
    if (!s.isEmpty())
    {
        new_colour = s.toStdString();
    }

    s = ui.priceLineEdit->text();
    if (!s.isEmpty())
    {
        new_price = s.toDouble();
    }

    s = ui.quantityLineEdit->text();
    if (!s.isEmpty())
    {
        new_quantity = s.toInt();
    }

    try
    {
        this->cont.updateTrench(link, new_size, new_colour, new_price, new_quantity);
        QMessageBox::information(this, "Success", "Update done", QMessageBox::Ok);
        this->handleDisplay();
    }
    catch (TrenchRepoException& ex)
    {
        QMessageBox::information(this, "Error",ex.message().c_str(), QMessageBox::Ok);
    }
}

void TrenchCoats::handleDisplayDeleted()
{
    vector<TrenchCoat> trenches = this->cont.getAllDeleted();
    ui.coatsList->clear();
    for (auto t : trenches)
    {
        ui.coatsList->addItem(QString::fromStdString(t.toString()));
    }
}

void TrenchCoats::handleFilter()
{
    string text = ui.filterLineEdit->text().toStdString();
    vector<TrenchCoat> trenches = this->cont.filterByString(text);
    ui.coatsList->clear();
    for (auto t : trenches)
    {
        ui.coatsList->addItem(QString::fromStdString(t.toString()));
    }
}

void TrenchCoats::handleSeeImage()
{
    if (ui.shoppingBasketList->selectedItems().size() > 0)
    {
        string obj = ui.shoppingBasketList->currentItem()->text().toStdString();
        vector<string> atr = tokenize(obj, ',');
        string link = "start " + atr[4];
        system(link.c_str());
    }
}

void TrenchCoats::handleAddToBasket()
{
    string obj = ui.shoppingBasketList->currentItem()->text().toStdString();
    vector<string> atr = tokenize(obj, ',');
    int size = 0;
    if (atr[0] == "XS")
    {
        size = 1;
    }
    if (atr[0] == "S")
    {
        size = 2;
    }
    if (atr[0] == "M")
    {
        size = 3;
    }
    if (atr[0] == "L")
    {
        size = 4;
    }
    if (atr[0] == "XL")
    {
        size = 5;
    }
    if (atr[0] == "XXL")
    {
        size = 6;
    }
    TrenchCoat t{ size, atr[1], stod(atr[2]), stoi(atr[3]), atr[4] };
    int data_option = ui.savingOptionBox->currentIndex();
    this->cont.addTrenchToBasket(t, this->cont.getDataOption());
    QMessageBox::information(this, "Added to basket", "Trench coat added to basket successfully!", QMessageBox::Ok);
}

void TrenchCoats::handleShowBasket()
{
    if (this->cont.getDataOption() == 1)
    {
        system("start basket.csv");
    }
    else
    {
        system("start basket.html");
    }
}

void TrenchCoats::handleUndo()
{
    try
    {
        this->cont.undoAction();
        this->handleDisplay();
    }
    catch (exception& ex)
    {
        QMessageBox::information(this, "Error", ex.what(), QMessageBox::Ok);
    }
}

void TrenchCoats::handleRedo()
{
    try
    {
        this->cont.redoAction();
        this->handleDisplay();
    }
    catch (exception& ex)
    {
        QMessageBox::information(this, "Error", ex.what(), QMessageBox::Ok);
    }
}

void TrenchCoats::handleShowTable()
{
    QWidget* tableWidget = new QWidget;
    QGridLayout* tableLayout = new QGridLayout(tableWidget);

    TrenchTableModel* basketTableModel = new TrenchTableModel(this->cont.getBasket());
    QTableView* basketTable = new QTableView;
    basketTable->setModel(basketTableModel);

    tableLayout->addWidget(basketTable, 0, 1);
    
    basketTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tableWidget->resize(600, 400);

    tableWidget->show();
}

