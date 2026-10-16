#include <memory>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "tower_interfaces/msg/piece_array.hpp"

// Reception minimale : le choix des pieces et la commande du bras restent a ajouter.
class TowerController : public rclcpp::Node
{
public:
  TowerController()
  : Node("tower_controller")
  {
    subscription_ = create_subscription<tower_interfaces::msg::PieceArray>(
      "/detected_pieces", 10,
      [this](tower_interfaces::msg::PieceArray::ConstSharedPtr observation) {
        // Remplacer le vecteur : une observation vide efface les anciennes pieces.
        pieces_ = observation->pieces;
        header_ = observation->header;
        RCLCPP_INFO(get_logger(), "Vecteur recu : %zu piece(s), repere=%s",
          pieces_.size(), header_.frame_id.c_str());
        for (const auto & piece : pieces_) {
          // Centre 3D de l'objet en metres, deja fourni par la perception.
          // La pose de la pince sera calculee a partir de ce centre et de l'outil.
          const auto & centre = piece.pose.pose.position;
          RCLCPP_INFO(get_logger(), "id=%u couleur=%s centre=[%.3f, %.3f, %.3f] m",
            piece.id, piece.color.c_str(), centre.x, centre.y, centre.z);
        }
        // La future strategie pourra exploiter pieces_ ici.
      });
  }

private:
  std::vector<tower_interfaces::msg::Piece> pieces_;
  std_msgs::msg::Header header_;
  rclcpp::Subscription<tower_interfaces::msg::PieceArray>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TowerController>());
  rclcpp::shutdown();
  return 0;
}
