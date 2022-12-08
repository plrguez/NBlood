#! /bin/sh
set -e

games=("duke3d" "rr" "rrra" "nam" "napalm" "ww2gi")
names=("Duke Nukem 3D: Atomic Edition" "Redneck Rampage" "Redneck Rampage Rides Again" "NAM" "NAPALM" "World War II GI")
descriptions=("Duke Nukem 3D: Atomic Edition" "Redneck Rampage" "Redneck Rampage Rides Again" "NAM" "NAPALM" "World War II GI")
icons=("duke3d" "rr" "rrra" "NAM" "NAPALM" "WW2GI")
grp=("DUKE3D.GRP" "REDNECK.GRP" "REDNECK.GRP" "NAM.GRP" "NAPALM.GRP" "WW2GI.GRP")
cfg=("duke3d-ar.cfg" "rr.cfg" "rrra.cfg" "nam.cfg" "napalm.cfg" "ww2gi.cfg")

if [ -z "${TARGET}" ] ; then
	CURRENT_TARGET=gcw0
else
	CURRENT_TARGET=${TARGET}
fi

if [ -z "${SPLIT}" ] ; then
	SPLIT=no
fi

if [ ${CURRENT_TARGET} == "retrofw" ] ; then
	GRP_EXTERNAL_DIR="/media/mmcblk1p1/rednukem"
	GRP_INTERNAL_DIR="/media/home/retrofw/.config/rednukem"
else
	GRP_EXTERNAL_DIR="/media/sdcard/rednukem"
	GRP_INTERNAL_DIR="/media/data/local/home/.config/rednukem"
fi

DESKTOP_FILES=""

# create opk
for iopk in ${!games[@]}; do
	CURRENT_DESKTOP=${games[iopk]}.${CURRENT_TARGET}.desktop

cat > ${CURRENT_DESKTOP} <<EOF
[Desktop Entry]
Name=${names[iopk]}
Comment=${descriptions[iopk]}
Exec=rednukem -gamegrp ${grp[iopk]} -j ${GRP_EXTERNAL_DIR}/${games[iopk]} -j ${GRP_INTERNAL_DIR}/${games[iopk]} -cfg ${cfg[iopk]}
Terminal=false
Type=Application
StartupNotify=true
Icon=${icons[iopk]}
Categories=games;
X-OD-Manual=readme.rednukem.txt
EOF

	if [ ${SPLIT} == "yes" ] ; then
		OPK_NAME=rednukem-${games[iopk]}-${CURRENT_TARGET}.opk
		echo ${OPK_NAME}

		FLIST="${CURRENT_DESKTOP}"
		FLIST="${FLIST} ./od-assets/${icons[iopk]}.png"
		FLIST="${FLIST} ./od-assets/readme.rednukem.txt"
		FLIST="${FLIST} rednukem"

		rm -f ${OPK_NAME}
		mksquashfs ${FLIST} ${OPK_NAME} -all-root -no-xattrs -noappend -no-exports
		cat ${CURRENT_DESKTOP}
		rm -f ${CURRENT_DESKTOP}
	else
		DESKTOP_FILES="${DESKTOP_FILES} ${CURRENT_DESKTOP}"
		FLIST="${FLIST} ./od-assets/${icons[iopk]}.png"
	fi
done

if [ ${SPLIT} == "no" ] ; then
	OPK_NAME=rednukem-${CURRENT_TARGET}.opk
	echo ${OPK_NAME}

	FLIST="${DESKTOP_FILES} ${FLIST}"
	FLIST="${FLIST} rednukem"
	FLIST="${FLIST} ./od-assets/readme.rednukem.txt"

	rm -f ${OPK_NAME}
	mksquashfs ${FLIST} ${OPK_NAME} -all-root -no-xattrs -noappend -no-exports

	cat ${DESKTOP_FILES}
	rm -f ${DESKTOP_FILES}
fi
