#include <pugixml.hpp>
#include <iostream>

namespace {
    char const* cases[] = {
     R"(<root><metadata>Trying to change this</metadata></root>)",
     R"(<root><metadata><surprise/></metadata></root>)",
     R"(<root><metadata>mixed<surprise/>bag</metadata></root>)",
     R"(<root><metadata><![CDATA[mixed<surprise/>bag]]></metadata></root>)",
     R"(<root><metadata><!-- comment please -->outloud<!-- hidden --></metadata></root>)",
     R"(<root>
  <metadata>Trying to change this</metadata>
  <body>
    <salad>Greek Caesar</salad>
   </body>
</root>)",
     //These no longer crash:
     R"(<root><metadata></metadata></root>)",
     R"(<root><metadata/></root>)",
     // more edge-cases in the predecessor chain
     R"(<root></root>)",
     R"(<root><no-metadata/></root>)",
     R"(<bogus/>)",
    };
}

int main() {
    auto const fmt = pugi::format_raw | pugi::format_no_declaration;
    for (auto& xml : cases) {
        std::cout << "Input: " << xml << "\n";

        pugi::xml_document doc;
        doc.load_string(xml);

        if (auto meta = doc.select_single_node("//root/metadata").node()) {
            auto parent = meta.parent();
            parent
                .insert_child_before("meradata", meta)
                .text().set("changed");
            parent.remove_child(meta);
        }
        
        doc.save(std::cout << "Output: ", "", fmt);
        std::cout << "\n--\n";
    }
}