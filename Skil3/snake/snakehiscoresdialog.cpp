#include "snakehiscoresdialog.h"
#include "ui_snakehiscoresdialog.h"

SnakeHiscoresDialog::SnakeHiscoresDialog(QWidget *parent) : QDialog(parent), ui(new Ui::SnakeHiscoresDialog) {
    ui -> setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.35);
    setWindowIcon(QIcon("./data/icons/snake.png"));
    ui -> tableView -> setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> tableView -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

SnakeHiscoresDialog::~SnakeHiscoresDialog() {
    delete ui;
}

void SnakeHiscoresDialog::on_closeButton_clicked() {
    this -> close();
}

void SnakeHiscoresDialog::setData(Storage *storage, int grid) {
    vector<SnakeScore> scores = storage -> getSnakeScores(grid);
    vector<SnakeScore> topTenScores;
    for(int i = 0; i < 10; i++) {
        int idx = 0;
        if(scores.size() <= 0) {
            break;
        }
        for(unsigned int j = 1; j < scores.size(); j++) {
            if(scores[j].getScore() > scores[idx].getScore()) {
                idx = j;
            }
        }
        topTenScores.push_back(scores[idx]);
        scores.erase(scores.begin() + idx);
    }
    setWindowTitle("Top "+QString::fromStdString(to_string(topTenScores.size()))+" hiscores - grid size "+QString::fromStdString(to_string(grid)));
    QStandardItemModel *model = new QStandardItemModel(topTenScores.size(), 2);
    model -> setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model -> setHorizontalHeaderItem(1, new QStandardItem(QString("Score")));
    for(unsigned int i = 0; i < topTenScores.size(); i++) {
        QStandardItem *row1 = new QStandardItem(QString::fromStdString(topTenScores[i].getName()));
        QStandardItem *row2 = new QStandardItem(QString::fromStdString(to_string(topTenScores[i].getScore())));
        model -> setItem(i, 0, row1);
        model -> setItem(i, 1, row2);
    }
    ui -> tableView -> setModel(model);
}
