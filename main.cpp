#include <openvdb/openvdb.h>
#include <openvdb/points/PointDataGrid.h>
#include <openvdb/io/File.h>

int main()
{
    // OpenVDBを初期化する
    openvdb::initialize();

    // 粒子間距離が0.1の粒子の位置座標を生成する
    std::vector<openvdb::Vec3R> positions;
    double particleSpacing = 0.1;
    int width = 20;   // 幅
    int height = 20;  // 高さ
    int depth = 10;   // 奥行き

    // 左半分に水の塊を配置
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int z = 0; z < depth; ++z) {
                positions.emplace_back(x * particleSpacing, y * particleSpacing, z * particleSpacing);
            }
        }
    }

    // PointDataGridを作成する
    openvdb::points::PointDataGrid::Ptr pointGrid = openvdb::points::PointDataGrid::create(positions);

    // VDBファイルに保存する
    std::string filename = "dam_break.vdb";
    openvdb::io::File file(filename);
    file.write({ pointGrid });
    file.close();

    return 0;
}
