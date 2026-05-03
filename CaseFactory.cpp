class CaseFactory {
    public:
        static Case* creerCase(const string& type) {
            if (type == "MUR") {
                return new Mur();
            }
            if (type == "PASSAGE") {
                return new Passage();
            }
            if (type == "MONSTRE") {
                return new Monstre();
            }
            if (type == "PIEGE") {
                return new Piege();
            }
            if (type == "TRESOR") {
                return new Tresor();
            }
            return nullptr;
        }
};