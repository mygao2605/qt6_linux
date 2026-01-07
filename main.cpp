#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QDirIterator>
#include <QDebug>

int main(int argc, char *argv[])
{
    // Thiết lập thuộc tính đồ họa cho i.MX8 (Tùy chọn nhưng khuyến nghị)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // --- ĐOẠN MÃ DEBUG TÀI NGUYÊN (Có thể xóa sau khi chạy thành công) ---
    qDebug() << "--- Listing all embedded resources ---";
    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qDebug() << "Found resource:" << it.next();
    }
    qDebug() << "---------------------------------------";
    // ------------------------------------------------------------------

    QQmlApplicationEngine engine;

    /**
     * GIẢI THÍCH ĐƯỜNG DẪN:
     * Trong CMakeLists.txt bạn đặt: URI my.app
     * Qt 6 sẽ tự động nhúng file main.qml vào module này.
     * Đường dẫn chuẩn sẽ là: qrc:/qt/qml/ + [Tên Module thay dấu chấm bằng dấu gạch chéo]
     * Hoặc đơn giản nhất là: qrc:/[URI_Path]/main.qml
     */
    const QUrl url(QStringLiteral("qrc:/my/app/main.qml"));

    // Kiểm tra xem việc tạo đối tượng QML có thành công không
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) {
                qCritical() << "CRITICAL: Could not load QML from URL:" << url;
                QCoreApplication::exit(-1);
            } else {
                qInfo() << "SUCCESS: QML loaded successfully!";
            }
        }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}