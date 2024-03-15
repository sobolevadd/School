var root = document.body;

// array of all available images - typically loaded from a different source file
if (typeof data === "undefined") {
    var data = [];
}

// width + gap of one card in the gallery
const card_width = 150;
const card_height = card_width;
const card_gap = 10;

var Gallery = {
    // array of images that were loaded on a page
    visible_data: [],

    loadImages: function () {
        //const width = window.visualViewport.width;
        const height = window.visualViewport.height;  // height of the viewport
        var container = document.getElementById("gallery-container");
        if (container === null) {
            return;
        }
        const width = container.offsetWidth;  // width of the container

        const cards_per_row = Math.floor((width + card_gap) / (card_width + card_gap));
        const cards_per_col = Math.floor((height + card_gap) / (card_height + card_gap));
        // count cards per viewport, minus cards in the last row if it is not complete
        const cards_per_viewport = cards_per_row * cards_per_col - this.visible_data.length % cards_per_row;
        // count cards to be loaded
        const count = Math.min(cards_per_viewport, data.length - this.visible_data.length);

        const offset = this.visible_data.length;
        for (let index = 0; index < count; index++) {
            if (offset + index < data.length) {
                this.visible_data.push(data[offset + index]);
            }
        }
        console.log("Loaded " + count + " images.");
    },

    view: function () {
        console.log("Gallery.view");
        return m("main", { class: "gallery-view" }, [
            m("h1", "Pet Gallery"),
            m("p", data.length + " images"),
            m("section", { id: "gallery-container" }, this.visible_data.map(function (img, index) {
                // img -> URL of a true image (should be a thumbnail...)
                // a -> URL of a view
                var view = "#!/image/" + index
                return m("a", { href: view }, m("img", { src: img }))
            })),
            //m("button", { class: "load", onclick: this.loadImages }, "Load more..."),
        ]);
    },

    oncreate: function () {
        console.log("Gallery.oncreate");
        // load first batch of images after the component was rendered and we know the width of the container
        if (this.visible_data.length == 0) {
            this.loadImages();
            m.redraw();
        }
    }
}

var Image = {
    view: function (vnode) {
        // first get the parameter from vnode
        id = Number(vnode.attrs.id);
        // calculate IDs of the previous and next images
        const id_prev = (id > 0) ? (id - 1) : data.length - 1;
        const id_next = (id < data.length - 1) ? (id + 1) : 0;
        // get the image URL
        const img = (id < data.length - 1) ? data[id] : "";
        // construct a view
        return m("main", { class: "image-view" }, [
            m("header", [
                m("p", id + " / " + data.length),
                m("p", img.split("/")[1]),
                m("a", { href: "#!/gallery" }, "🏠"),
            ]),
            m("section", [
                m("a", { class: "button-prev", href: "#!/image/" + id_prev },
                    m("p", "◀")
                ),
                m("a", { class: "button-next", href: "#!/image/" + id_next },
                    m("p", "▶")
                ),
                m("div", m("img", { src: img })),
            ]),
        ]);
    }
}

m.route(root, "/gallery", {
    "/gallery": Gallery,
    "/image/:id": Image,
})

// redraw the UI after the whole page was loaded
// (the images may be defined in an external file after this one)
window.onload = (event) => {
    console.log("window.onload");
    console.log(m.route.get());
    if (m.route.get() == "/gallery") {
        Gallery.oncreate();
    }
    else if (m.route.get().startsWith("/image")) {
        m.redraw();
    }
}

// infinite scrolling
let ticking = false;
document.addEventListener("scroll", (event) => {
    // check if the Gallery component is active
    if (m.route.get() != "/gallery") {
        return;
    }
    // check if we are at the bottom of the page
    if ((window.innerHeight + Math.round(window.scrollY)) >= document.body.offsetHeight) {
        // using window.requestAnimationFrame throttles the event handling
        if (!ticking) {
            ticking = true;
            window.requestAnimationFrame(function () {
                // load more data
                Gallery.loadImages();
                // redraw the UI
                m.redraw();
                // unlock the event handler
                ticking = false;
            });
        }
    }
});
